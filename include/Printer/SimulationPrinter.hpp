#pragma once
#include <Eigen/Dense>
#include <complex>
#include <vector>
#include "Components/VoltageSource.hpp"

namespace SimulationPrinter
{
    template <typename Scalar>
    void printSolution(const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &x, int nodeCount, int const voltageSourceCount);
}
