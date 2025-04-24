#pragma once
#include "Component.hpp"

// Interface for components that stamp into both Matrix and Vector
class MatrixVectorStamper : public virtual Component
{
public:
    virtual void stampMatrixVectorDouble(Matrix<double> &A, Vector<double> &z) const = 0;
    virtual void stampMatrixVectorComplex(Matrix<std::complex<double>> &A, Vector<std::complex<double>> &z) const = 0;
};