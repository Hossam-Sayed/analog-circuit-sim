#include "Simulation/SimulationFactory.hpp"
#include <iostream>

std::vector<std::unique_ptr<SimulationStrategy>> SimulationFactory::create(const NetlistParser &parser)
{
    std::vector<std::unique_ptr<SimulationStrategy>> strategies;

    if (parser.getHasDC())
        strategies.push_back(std::make_unique<DCAnalysis>());

    if (parser.getHasAC())
        strategies.push_back(std::make_unique<ACAnalysis>());

    // TODO: Placeholder for TRAN later
    // if (parser.getHasTRAN())
    //     strategies.push_back(std::make_unique<TransientAnalysis>());

    return strategies;
}
