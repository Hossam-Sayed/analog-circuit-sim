#pragma once
#include "Simulation/SimulationStrategy.hpp"
#include "Simulation/DCAnalysis.hpp"
#include "Simulation/ACAnalysis.hpp"
#include <memory>
#include <vector>

class SimulationFactory
{
public:
    static std::vector<std::unique_ptr<SimulationStrategy>> create(const NetlistParser &parser);
};
