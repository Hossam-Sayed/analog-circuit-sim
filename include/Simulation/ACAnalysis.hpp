#pragma once
#include "SimulationStrategy.hpp"

class ACAnalysis : public SimulationStrategy
{
public:
    void run(const NetlistParser &netlist) override;
};
