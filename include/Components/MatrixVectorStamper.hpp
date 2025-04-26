#pragma once
#include "Component.hpp"

// Interface for components that stamp into both Matrix and Vector
class MatrixVectorStamper : public virtual Component
{
public:
    virtual void stampMatrixVectorDC(DoubleMatrix &A, DoubleVector &z) const = 0;
    virtual void stampMatrixVectorAC(ComplexMatrix &A, ComplexVector &z, const double &omega) const = 0;
};