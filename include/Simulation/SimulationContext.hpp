#pragma once
#include "Common/SimulationType.hpp"

class SimulationContext
{
public:
    SimulationType type = SimulationType::NONE;
    double omega = 0.0, timestep = 0.0, time = 0.0;

    void init() { clear(); }
    void clear() { type = SimulationType::NONE, omega = 0.0, timestep = 0.0, time = 0.0; }
};