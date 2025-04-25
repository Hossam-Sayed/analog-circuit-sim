#pragma once
#include "Common/SimulationType.hpp"

class SimulationContext
{
public:
    SimulationType type = SimulationType::NONE;
    double omega = 0.0, timestep = 0.0, time = 0.0;

    bool isDC() const { return type == SimulationType::OP; }
    bool isAC() const { return type == SimulationType::AC; }
    bool isTRAN() const { return type == SimulationType::TRAN; }

    void init() { clear(); }
    void clear() { type = SimulationType::NONE, omega = 0.0, timestep = 0.0, time = 0.0; }
};
