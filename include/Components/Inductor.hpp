#pragma once
#include "MatrixVectorStamper.hpp"
#include "IndexedComponent.hpp"

class Inductor : public MatrixVectorStamper, public IndexedComponent
{
public:
    Inductor(const std::string &name, int node1, int node2, double inductance);

    void stampMatrixVectorDC(DoubleMatrix &A, DoubleVector &z) const override;
    void stampMatrixVectorAC(ComplexMatrix &A, ComplexVector &z, const double &omega) const override;

private:
    int node1, node2;
    double inductance;
};
