#pragma once
#include "MNABuilder.hpp"
#include <Eigen/SparseLU>

class LinearSolver
{
public:
    // TODO: Later be moved into the parent Solver class
    // Reusable method for solving linear systems
    template <typename Scalar>
    static Eigen::Matrix<Scalar, Eigen::Dynamic, 1> solve(
        const Eigen::SparseMatrix<Scalar> &A_sparse,
        Eigen::SparseLU<Eigen::SparseMatrix<Scalar>> &solver,
        const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &z);

    static Eigen::VectorXd solveDC(const NetlistParser &netlist);
    static Eigen::VectorXcd solveAC(const NetlistParser &netlist, SimulationContext ctx);
};