#pragma once
#include "MatrixVectorStamperImpl.hpp"
#include "IndexedComponent.hpp"

class VoltageSource : public MatrixVectorStamperImpl<VoltageSource>, public IndexedComponent
{
public:
    VoltageSource(const std::string &name, int nodePos, int nodeNeg, double voltage);

    template <typename T>
    void stamp(Matrix<T> &A, Vector<T> &z) const;

private:
    int nodePos, nodeNeg;
    double voltage;
};
