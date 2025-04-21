#include "Core/LinearSolver.hpp"
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
    Eigen::MatrixXd A;
    Eigen::VectorXd z;
    MNABuilder::build<double>(netlist, A, z);

    Eigen::SparseMatrix<double> A_sparse = A.sparseView();
    Eigen::SparseLU<Eigen::SparseMatrix<double>> solver;

    return solve(A_sparse, solver, z);
}

Eigen::VectorXcd LinearSolver::solveAC(const NetlistParser &netlist)
{
    // Incomplete AC analysis implementation
    Eigen::MatrixXcd A;
    Eigen::VectorXcd z;
    MNABuilder::build<std::complex<double>>(netlist, A, z);

    Eigen::SparseMatrix<std::complex<double>> A_sparse = A.sparseView();
    Eigen::SparseLU<Eigen::SparseMatrix<std::complex<double>>> solver;

    return solve(A_sparse, solver, z);
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
