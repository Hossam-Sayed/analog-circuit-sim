#pragma once
#include "Component.hpp"
#include "Simulation/SimulationContext.hpp"

// Interface for components that stamp into Matrix<T>
class MatrixStamper : public virtual Component
{
public:
    virtual void stampMatrixDC(Matrix<double> &A) const = 0;
    virtual void stampMatrixAC(Matrix<std::complex<double>> &A, const SimulationContext &ctx) const = 0;
};
