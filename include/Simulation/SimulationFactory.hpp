#pragma once
#include "Simulation/SimulationStrategy.hpp"
#include "Simulation/DCAnalysis.hpp"
#include "Simulation/ACAnalysis.hpp"
#include "Parser/NetlistParser.hpp"
#include <memory>

class SimulationFactory
{
public:
    static std::unique_ptr<SimulationStrategy> create(SimulationType type);
};