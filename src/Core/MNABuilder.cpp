#include "Core/MNABuilder.hpp"
#include "Components/MatrixStamper.hpp"

template <typename Scalar>
void MNABuilder::build(const NetlistParser &netlist,
                       Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> &A,
                       Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &z)
{
    int n = netlist.getMaxNode();

    // Sum the total number of indexed components (i.e., extra variables)
    int m = 0;
    for (const auto &[type, comps] : netlist.getIndexedComponents())
        m += comps.size();

    int size = n + m;
    A = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>::Zero(size, size);
    z = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>::Zero(size);

    if constexpr (std::is_same_v<Scalar, double>)
    {
        for (const auto &m : netlist.getMatrixStampers())
            m->stampMatrixDouble(A);
        for (const auto &mv : netlist.getMatrixVectorStampers())
            mv->stampMatrixVectorDouble(A, z);
        for (const auto &v : netlist.getVectorStampers())
            v->stampVectorDouble(z);
    }
    else
    {
        for (const auto &m : netlist.getMatrixStampers())
            m->stampMatrixComplex(A);
        for (const auto &mv : netlist.getMatrixVectorStampers())
            mv->stampMatrixVectorComplex(A, z);
        for (const auto &v : netlist.getVectorStampers())
            v->stampVectorComplex(z);
    }
}

// Explicit instantiations
template void MNABuilder::build<double>(const NetlistParser &, Eigen::MatrixXd &, Eigen::VectorXd &);
template void MNABuilder::build<std::complex<double>>(const NetlistParser &, Eigen::MatrixXcd &, Eigen::VectorXcd &);