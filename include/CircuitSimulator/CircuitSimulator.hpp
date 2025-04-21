#pragma once
#include "Parser/NetlistParser.hpp"
#include "Simulation/SimulationStrategy.hpp"
#include <memory>

class CircuitSimulator
{
    NetlistParser parser;
    std::unique_ptr<SimulationStrategy> strategy;

public:
    explicit CircuitSimulator(const std::string &netlistFile);
    void run();
};