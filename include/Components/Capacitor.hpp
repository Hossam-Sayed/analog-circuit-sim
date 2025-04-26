#pragma once
#include "MatrixStamper.hpp"

class Capacitor : public MatrixStamper
{
public:
    Capacitor(const std::string &name, int node1, int node2, double capacitance);

    void stampMatrixDC(Matrix<double> &A) const override;
    void stampMatrixAC(Matrix<std::complex<double>> &A, const double omega) const override;

private:
    int node1, node2;
    double capacitance;
};
