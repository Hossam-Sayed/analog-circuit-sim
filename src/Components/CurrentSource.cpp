#include "Components/CurrentSource.hpp"

CurrentSource::CurrentSource(const std::string &name, int node1, int node2, double current)
    : node1(node1), node2(node2), current(current)
{
    setName(name);
}

void CurrentSource::stampVectorDC(Vector<double> &z) const
{
    stampCurrentSource<double>(z);
}

void CurrentSource::stampVectorAC(Vector<std::complex<double>> &z, const double omega) const
{
    stampCurrentSource<std::complex<double>>(z);
}

template <typename T>
void CurrentSource::stampCurrentSource(Vector<T> &z) const
{
    if (node1 >= 0)
        z(node1) -= T(current); // Negative because current leaves node1
    if (node2 >= 0)
        z(node2) += T(current); // Enters node2
}
