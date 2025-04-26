#pragma once
#include "Component.hpp"

// Interface for components that stamp into Matrix<T>
class MatrixStamper : public virtual Component
{
public:
    virtual void stampMatrixDC(Matrix<double> &A) const = 0;
    virtual void stampMatrixAC(Matrix<std::complex<double>> &A, const double omega) const = 0;
};
