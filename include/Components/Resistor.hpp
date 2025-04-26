#pragma once
#include "MatrixStamper.hpp"

class Resistor : public MatrixStamper
{
public:
    Resistor(const std::string &name, int node1, int node2, double resistance);

    void stampMatrixDC(Matrix<double> &A) const override;
    void stampMatrixAC(Matrix<std::complex<double>> &A, const double omega) const override;

    template <typename T>
    void stampResistor(Matrix<T> &A) const;

private:
    int node1, node2;
    double resistance;
};