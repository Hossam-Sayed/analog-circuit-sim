#pragma once
#include "Component.hpp"

// Interface for components that stamp into both Matrix and Vector
class MatrixVectorStamper : public virtual Component
{
public:
    virtual void stampMatrixVectorDC(Matrix<double> &A, Vector<double> &z) const = 0;
    virtual void stampMatrixVectorAC(Matrix<std::complex<double>> &A,
                                     Vector<std::complex<double>> &z,
                                     const double omega) const = 0;
};