#pragma once
#include "MatrixStamper.hpp"

template <typename Impl>
class MatrixStamperImpl : public MatrixStamper
{
public:
    void stampMatrixDouble(Matrix<double> &A) const override
    {
        static_cast<const Impl *>(this)->template stamp<double>(A);
    }

    void stampMatrixComplex(Matrix<std::complex<double>> &A) const override
    {
        static_cast<const Impl *>(this)->template stamp<std::complex<double>>(A);
    }
};