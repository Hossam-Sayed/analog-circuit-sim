#pragma once
#include "Component.hpp"

// Interface for components that stamp into Matrix<T>
class MatrixStamper : public virtual Component
{
public:
    virtual void stampMatrixDC(DoubleMatrix &A) const = 0;
    virtual void stampMatrixAC(ComplexMatrix &A, const double &omega) const = 0;
};
