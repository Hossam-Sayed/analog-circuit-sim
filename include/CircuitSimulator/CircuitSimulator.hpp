#pragma once
#include "Parser/NetlistParser.hpp"
#include "Simulation/SimulationStrategy.hpp"
#include <vector>
#include <memory>
#include <string>

class CircuitSimulator
{
public:
    explicit CircuitSimulator(const std::string &netlistFile);
    void run();

private:
    NetlistParser parser;
    std::vector<std::unique_ptr<SimulationStrategy>> strategies;
};
