#pragma once
#include "MatrixVectorStamperImpl.hpp"
#include "IndexedComponent.hpp"

class VoltageSource : public MatrixVectorStamperImpl<VoltageSource>, public IndexedComponent
{
public:
    VoltageSource(std::string name, int nPos, int nNeg, double v);

    template <typename T>
    void stamp(Matrix<T> &A, Vector<T> &z) const;

private:
    int nodePos, nodeNeg;
    double voltage;
};
