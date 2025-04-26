#pragma once
#include "MatrixStamper.hpp"

class Capacitor : public MatrixStamper
{
public:
    Capacitor(const std::string &name, int node1, int node2, double capacitance);

    void stampMatrixDC(DoubleMatrix &A) const override;
    void stampMatrixAC(ComplexMatrix &A, const double &omega) const override;

private:
    int node1, node2;
    double capacitance;
};
