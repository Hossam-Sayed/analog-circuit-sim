#pragma once
#include "SimulationStrategy.hpp"

class DCAnalysis : public SimulationStrategy
{
public:
    void run(const NetlistParser &netlist) override;
};