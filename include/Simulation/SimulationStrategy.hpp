#pragma once
#include "Parser/NetlistParser.hpp"

class SimulationStrategy
{
public:
    virtual void run(const NetlistParser &netlist) = 0;
    virtual ~SimulationStrategy() = default;
};
