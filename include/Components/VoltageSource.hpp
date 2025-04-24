#pragma once
#include "MatrixVectorStamperImpl.hpp"
#include "IndexedComponent.hpp"

class VoltageSource : public MatrixVectorStamperImpl<VoltageSource>, public IndexedComponent
{
public:
    VoltageSource(std::string vName, int nPos, int nNeg, double v);

    template <typename T>
    void stamp(Matrix<T> &A, Vector<T> &z) const;

    std::string getName() const;

private:
    std::string name;
    int nodePos, nodeNeg;
    double voltage;
};
