#pragma once
#include <Eigen/Dense>
#include <complex>
#include <vector>
#include "components/VoltageSource.hpp"

namespace SimulationPrinter
{
    template <typename Scalar>
    void printSolution(const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &x, int nodeCount, const std::vector<VoltageSource> &vsrcs);
}
