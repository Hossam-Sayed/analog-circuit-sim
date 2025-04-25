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

    strategies = SimulationFactory::create(parser);
}

void CircuitSimulator::run()
{
    if (strategies.empty())
    {
        std::cerr << "No valid simulation strategies found.\n";
        return;
    }

    for (const auto &strategy : strategies)
    {
        strategy->run(parser);
        std::cout << "----------------------------------------\n";
    }
}
