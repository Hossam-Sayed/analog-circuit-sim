#pragma once

#include <Eigen/Dense>
#include <complex>
#include <unordered_map>
#include "Components/IndexedComponent.hpp"
#include "Common/IndexType.hpp"
#include "Core/ACSweepPoint.hpp"

namespace SimulationPrinter
{
    template <typename Scalar>
    void printSolution(
        const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &x,
        const int &nodeCount,
        const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &indexedComponents);

    void printACSweep(const std::vector<ACSweepPoint> &results,
                      const int &nodeCount,
                      const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &indexedComponents);

}
