#include "Components/Capacitor.hpp"

Capacitor::Capacitor(const std::string &name, int node1, int node2, double capacitance)
    : node1(node1), node2(node2), capacitance(capacitance)
{
    setName(name);
}

void Capacitor::stampMatrixDC(DoubleMatrix &A) const { return; }

void Capacitor::stampMatrixAC(ComplexMatrix &A, const double &omega) const
{
    if (std::abs(omega) < 1e-12)
        return;

    std::complex<double> jomegaC = std::complex<double>(0, omega * capacitance);

    if (node1 >= 0)
        A(node1, node1) += jomegaC;
    if (node2 >= 0)
        A(node2, node2) += jomegaC;
    if (node1 >= 0 && node2 >= 0)
    {
        A(node1, node2) -= jomegaC;
        A(node2, node1) -= jomegaC;
    }
}