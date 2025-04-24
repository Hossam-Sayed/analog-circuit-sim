#pragma once
#include "MatrixVectorStamper.hpp"

template <typename Impl>
class MatrixVectorStamperImpl : public MatrixVectorStamper
{
public:
    void stampMatrixVectorDouble(Matrix<double> &A, Vector<double> &z) const override
    {
        static_cast<const Impl *>(this)->template stamp<double>(A, z);
    }

    void stampMatrixVectorComplex(Matrix<std::complex<double>> &A, Vector<std::complex<double>> &z) const override
    {
        static_cast<const Impl *>(this)->template stamp<std::complex<double>>(A, z);
    }
};