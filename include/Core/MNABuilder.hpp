#pragma once
#include "Parser/NetlistParser.hpp"
#include "Simulation/SimulationContext.hpp"
#include <Eigen/Dense>
#include <complex>

class MNABuilder
{
public:
    static void buildDC(const NetlistParser &netlist,
                        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                        Eigen::Matrix<double, Eigen::Dynamic, 1> &z);
    static void buildAC(const NetlistParser &netlist,
                        const SimulationContext context,
                        Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> &A,
                        Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1> &z);
    static void buildTRAN(const NetlistParser &netlist,
                          const SimulationContext context,
                          Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                          Eigen::Matrix<double, Eigen::Dynamic, 1> &z);
};