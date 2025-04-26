#include "Core/LinearSolver.hpp"
#include "Simulation/ACParams.hpp"
#include <iostream>

template <typename Scalar>
Eigen::Matrix<Scalar, Eigen::Dynamic, 1>
LinearSolver::solve(const Eigen::SparseMatrix<Scalar> &A_sparse,
                    Eigen::SparseLU<Eigen::SparseMatrix<Scalar>> &solver,
                    const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &z)
{
    solver.analyzePattern(A_sparse);
    solver.factorize(A_sparse);

    if (solver.info() != Eigen::Success)
    {
        std::cerr << "Matrix factorization failed!\n";
        return {};
    }

    auto x = solver.solve(z);
    if (solver.info() != Eigen::Success)
    {
        std::cerr << "Solving failed!\n";
        return {};
    }

    return x;
}

Eigen::VectorXd LinearSolver::solveDC(const NetlistParser &netlist)
{
    int size = MNABuilder::getMatrixSize(netlist);
    Eigen::MatrixXd A(size, size);
    Eigen::VectorXd z(size);
    A = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>::Zero(size, size);
    z = Eigen::Matrix<double, Eigen::Dynamic, 1>::Zero(size);
    MNABuilder::stampDC(netlist, A, z);

    Eigen::SparseMatrix<double> A_sparse = A.sparseView();
    Eigen::SparseLU<Eigen::SparseMatrix<double>> solver;

    return solve(A_sparse, solver, z);
}

std::vector<ACSweepPoint> LinearSolver::solveAC(const NetlistParser &netlist)
{
    int size = MNABuilder::getMatrixSize(netlist);

    Eigen::MatrixXcd A(size, size);
    Eigen::VectorXcd z(size);

    std::vector<double> freqs = netlist.getACParams().getFrequencies();
    std::vector<ACSweepPoint> results;
    results.reserve(freqs.size()); // Reserve once to avoid reallocations

    Eigen::SparseLU<Eigen::SparseMatrix<std::complex<double>>> solver;

    // Instead of recreating A_sparse every time, define it once outside
    Eigen::SparseMatrix<std::complex<double>> A_sparse(size, size);

    for (std::size_t i = 0; i < freqs.size(); ++i)
    {
        double f = freqs[i];
        double omega = 2 * M_PI * f;

        // Reset A and z to zero without reallocating
        A.setZero();
        z.setZero();

        // Stamp matrices
        MNABuilder::stampAC(netlist, omega, A, z);

        // Update A_sparse efficiently
        A_sparse = A.sparseView();

        // Solve
        Eigen::VectorXcd x = solve(A_sparse, solver, z);

        // Emplace directly into the results vector (no redundant copies)
        results.emplace_back(ACSweepPoint{f, std::move(x)});
    }

    return results;
}

// Template instantiations (needed to avoid linker errors)
template Eigen::VectorXd LinearSolver::solve<double>(
    const Eigen::SparseMatrix<double> &,
    Eigen::SparseLU<Eigen::SparseMatrix<double>> &,
    const Eigen::VectorXd &);

template Eigen::VectorXcd LinearSolver::solve<std::complex<double>>(
    const Eigen::SparseMatrix<std::complex<double>> &,
    Eigen::SparseLU<Eigen::SparseMatrix<std::complex<double>>> &,
    const Eigen::VectorXcd &);
