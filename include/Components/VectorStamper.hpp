#pragma once
#include "Component.hpp"
#include "Simulation/SimulationContext.hpp"

// Interface for components that stamp into Vector<T>
class VectorStamper : public virtual Component
{
public:
    virtual void stampVectorDC(Vector<double> &z) const = 0;
    virtual void stampVectorAC(Vector<std::complex<double>> &z, const SimulationContext &ctx) const = 0;
};