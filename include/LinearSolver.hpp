#pragma once
#include <Eigen/SparseLU>
#include <Eigen/Dense>
#include <complex>
#include <iostream>
#include "NetlistParser.hpp"

class LinearSolver
{
public:
    static Eigen::VectorXd solveDC(const NetlistParser &netlist);
    static Eigen::VectorXcd solveAC(const NetlistParser &netlist);

private:
    template <typename Scalar>
    static void constructMNASystem(const NetlistParser &netlist,
                                   Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> &A,
                                   Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &z);
};
