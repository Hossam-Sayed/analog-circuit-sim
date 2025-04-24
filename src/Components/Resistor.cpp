#include "Components/Resistor.hpp"

Resistor::Resistor(const std::string &name, int n1, int n2, double r)
    : node1(n1), node2(n2), resistance(r)
{
    setName(name);
}

template <typename T>
void Resistor::stamp(Matrix<T> &A) const
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

// Explicit template instantiations
template void Resistor::stamp(Matrix<double> &A) const;
template void Resistor::stamp(Matrix<std::complex<double>> &A) const;
