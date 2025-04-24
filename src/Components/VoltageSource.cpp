#include "Components/VoltageSource.hpp"
#include "Parser/NetlistParser.hpp"

VoltageSource::VoltageSource(const std::string &name, int nodePos, int nodeNeg, double voltage)
    : nodePos(nodePos), nodeNeg(nodeNeg), voltage(voltage)
{
    setName(name);
}

template <typename T>
void VoltageSource::stamp(Matrix<T> &A, Vector<T> &z) const
{
    int idx = getIndex();

    if (nodePos >= 0)
    {
        A(nodePos, idx) += T(1);
        A(idx, nodePos) += T(1);
    }
    if (nodeNeg >= 0)
    {
        A(nodeNeg, idx) -= T(1);
        A(idx, nodeNeg) -= T(1);
    }

    z(idx) += T(voltage);
}

// Explicit instantiations
template void VoltageSource::stamp(Matrix<double> &A, Vector<double> &z) const;
template void VoltageSource::stamp(Matrix<std::complex<double>> &A, Vector<std::complex<double>> &z) const;
