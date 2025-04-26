#pragma once
#include "VectorStamper.hpp"

class CurrentSource : public VectorStamper
{
public:
    CurrentSource(const std::string &name, int node1, int node2, double current);

    void stampVectorDC(DoubleVector &z) const override;
    void stampVectorAC(ComplexVector &z, const double &omega) const override;

    template <typename T>
    void stampCurrentSource(Vector<T> &z) const;

private:
    int node1, node2;
    double current;
};