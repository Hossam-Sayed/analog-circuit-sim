#include "Components/CurrentSource.hpp"

CurrentSource::CurrentSource(const std::string &name, int node1, int node2, double current)
    : node1(node1), node2(node2), current(current)
{
    setName(name);
}

template <typename T>
void CurrentSource::stamp(Vector<T> &z) const
{
    if (node1 >= 0)
        z(node1) -= T(current); // Negative because current leaves node1
    if (node2 >= 0)
        z(node2) += T(current); // Enters node2
}

// Explicit template instantiations
template void CurrentSource::stamp(Vector<double> &z) const;
template void CurrentSource::stamp(Vector<std::complex<double>> &z) const;
