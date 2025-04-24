#pragma once
#include "VectorStamper.hpp"

template <typename Impl>
class VectorStamperImpl : public VectorStamper
{
public:
    void stampVectorDouble(Vector<double> &z) const override
    {
        static_cast<const Impl *>(this)->template stamp<double>(z);
    }

    void stampVectorComplex(Vector<std::complex<double>> &z) const override
    {
        static_cast<const Impl *>(this)->template stamp<std::complex<double>>(z);
    }
};