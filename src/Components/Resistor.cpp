#include "Components/Resistor.hpp"

Resistor::Resistor(const std::string &name, int node1, int node2, double resistance)
    : node1(node1), node2(node2), resistance(resistance)
{
    setName(name);
}

void Resistor::stampMatrixDC(Matrix<double> &A) const
{
    stampResistor<double>(A);
}

void Resistor::stampMatrixAC(Matrix<std::complex<double>> &A, const double omega) const
{
    stampResistor<std::complex<double>>(A);
}

template <typename T>
void Resistor::stampResistor(Matrix<T> &A) const
{
    T conductance = T(1.0) / T(resistance);
    if (node1 >= 0)
        A(node1, node1) += conductance;
    if (node2 >= 0)
        A(node2, node2) += conductance;
    if (node1 >= 0 && node2 >= 0)
    {
        A(node1, node2) -= conductance;
        A(node2, node1) -= conductance;
    }
}
