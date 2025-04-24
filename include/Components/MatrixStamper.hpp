#pragma once
#include "Component.hpp"

// Interface for components that stamp into Matrix<T>
class MatrixStamper : public virtual Component
{
public:
    virtual void stampMatrixDouble(Matrix<double> &A) const = 0;
    virtual void stampMatrixComplex(Matrix<std::complex<double>> &A) const = 0;
};