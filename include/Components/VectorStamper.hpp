#pragma once
#include "Component.hpp"

// Interface for components that stamp into Vector<T>
class VectorStamper : public virtual Component
{
public:
    virtual void stampVectorDouble(Vector<double> &z) const = 0;
    virtual void stampVectorComplex(Vector<std::complex<double>> &z) const = 0;
};