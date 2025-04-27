#include "Components/Inductor.hpp"

Inductor::Inductor(const std::string &name, int node1, int node2, double inductance)
    : node1(node1), node2(node2), inductance(inductance)
{
    setName(name);
}

void Inductor::stampMatrixVectorDC(DoubleMatrix &A, DoubleVector &z) const
{
    int idx = getIndex();

    // Stamp the KVL constraint (current flowing into the inductor)
    if (node1 >= 0)
    {
        A(node1, idx) += 1;
        A(idx, node1) += 1;
    }
    if (node2 >= 0)
    {
        A(node2, idx) -= 1;
        A(idx, node2) -= 1;
    }

    // In DC, an ideal inductor behaves like a short-circuit (0V across terminals)
    // => 0V constraint, so no contribution to the RHS vector (z)
}

void Inductor::stampMatrixVectorAC(ComplexMatrix &A, ComplexVector &z, const double &omega) const
{
    int idx = getIndex();

    std::complex<double> jomegaL(0, omega * inductance);

    if (node1 >= 0)
    {
        A(node1, idx) += 1.0;
        A(idx, node1) += 1.0;
    }
    if (node2 >= 0)
    {
        A(node2, idx) -= 1.0;
        A(idx, node2) -= 1.0;
    }

    // Stamp the inductance impedance between the node voltages
    A(idx, idx) -= jomegaL;
}
