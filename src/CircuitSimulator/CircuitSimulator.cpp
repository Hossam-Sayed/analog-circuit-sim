#include "CircuitSimulator/CircuitSimulator.hpp"
#include "Simulation/SimulationFactory.hpp"
#include <iostream>

CircuitSimulator::CircuitSimulator(const std::string &netlistFile)
{
    if (!parser.parse(netlistFile))
    {
        std::cerr << "Failed to parse netlist.\n";
        exit(1);
    }
    strategy = SimulationFactory::create(parser.getSimulationType());
}

void CircuitSimulator::run()
{
    if (!strategy)
    {
        std::cerr << "No valid strategy found.\n";
        return;
    }
    strategy->run(parser);
}