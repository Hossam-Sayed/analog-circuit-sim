#pragma once
#include "MatrixVectorStamper.hpp"
#include "IndexedComponent.hpp"

class VoltageSource : public MatrixVectorStamper, public IndexedComponent
{
public:
    VoltageSource(const std::string &name, int nodePos, int nodeNeg, double voltage);

    void stampMatrixVectorDC(Matrix<double> &A, Vector<double> &z) const override;
    void stampMatrixVectorAC(Matrix<std::complex<double>> &A,
                             Vector<std::complex<double>> &z,
                             const SimulationContext &ctx) const override;

    template <typename T>
    void stampVoltageSource(Matrix<T> &A, Vector<T> &z) const;

private:
    int nodePos, nodeNeg;
    double voltage;
};
