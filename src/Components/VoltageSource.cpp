#include "Components/VoltageSource.hpp"
#include "Parser/NetlistParser.hpp"

VoltageSource::VoltageSource(const std::string &name, int nodePos, int nodeNeg, double voltage)
    : nodePos(nodePos), nodeNeg(nodeNeg), voltage(voltage)
{
    setName(name);
}

void VoltageSource::stampMatrixVectorDC(DoubleMatrix &A, DoubleVector &z) const
{
    stampVoltageSource<double>(A, z);
}

void VoltageSource::stampMatrixVectorAC(ComplexMatrix &A, ComplexVector &z, const double &omega) const
{
    stampVoltageSource<std::complex<double>>(A, z);
}

template <typename T>
void VoltageSource::stampVoltageSource(Matrix<T> &A, Vector<T> &z) const
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
