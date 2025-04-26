#pragma once
#include "Component.hpp"

// Interface for components that stamp into Vector<T>
class VectorStamper : public virtual Component
{
public:
    virtual void stampVectorDC(DoubleVector &z) const = 0;
    virtual void stampVectorAC(ComplexVector &z, const double &omega) const = 0;
};