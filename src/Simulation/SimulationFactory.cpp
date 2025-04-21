#include "Simulation/SimulationFactory.hpp"
#include <iostream>

std::unique_ptr<SimulationStrategy> SimulationFactory::create(SimulationType type)
{
    switch (type)
    {
    case SimulationType::OP:
        return std::make_unique<DCAnalysis>();
    case SimulationType::AC:
        return std::make_unique<ACAnalysis>();
    default:
        std::cerr << "Unsupported or unimplemented simulation type.\n";
        return nullptr;
    }
}