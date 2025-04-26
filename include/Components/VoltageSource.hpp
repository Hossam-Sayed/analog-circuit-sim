#pragma once
#include "MatrixVectorStamper.hpp"
#include "IndexedComponent.hpp"

class VoltageSource : public MatrixVectorStamper, public IndexedComponent
{
public:
    VoltageSource(const std::string &name, int nodePos, int nodeNeg, double voltage);

    void stampMatrixVectorDC(DoubleMatrix &A, DoubleVector &z) const override;
    void stampMatrixVectorAC(ComplexMatrix &A, ComplexVector &z, const double &omega) const override;

    template <typename T>
    void stampVoltageSource(Matrix<T> &A, Vector<T> &z) const;

private:
    int nodePos, nodeNeg;
    double voltage;
};
