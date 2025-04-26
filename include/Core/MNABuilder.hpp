#pragma once
#include "Parser/NetlistParser.hpp"
#include "Simulation/ACParams.hpp"
#include <Eigen/Dense>
#include <complex>

class MNABuilder
{
public:
    static int getMatrixSize(const NetlistParser &netlist);
    static void stampDC(const NetlistParser &netlist,
                        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                        Eigen::Matrix<double, Eigen::Dynamic, 1> &z);
    static void stampAC(const NetlistParser &netlist,
                        double omega,
                        Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> &A,
                        Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1> &z);
    static void stampTRAN(const NetlistParser &netlist,
                          //    Send transParams here
                          Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                          Eigen::Matrix<double, Eigen::Dynamic, 1> &z);
};