#include "Core/MNABuilder.hpp"

template <typename Scalar>
void MNABuilder::build(const NetlistParser &netlist,
                       Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> &A,
                       Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &z)
{
    int n = netlist.getMaxNode();
    int m = netlist.getVoltageSources().size();
    int size = n + m;
    A = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>::Zero(size, size);
    z = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>::Zero(size);

    for (const auto &r : netlist.getResistors())
    {
        int a = r.node1, b = r.node2;
        Scalar g = Scalar(1.0) / Scalar(r.resistance);
        if (a != 0)
            A(a - 1, a - 1) += g;
        if (b != 0)
            A(b - 1, b - 1) += g;
        if (a != 0 && b != 0)
        {
            A(a - 1, b - 1) -= g;
            A(b - 1, a - 1) -= g;
        }
    }

    const auto &vsrcs = netlist.getVoltageSources();
    for (size_t k = 0; k < vsrcs.size(); ++k)
    {
        int a = vsrcs[k].node1, b = vsrcs[k].node2;
        Scalar v = Scalar(vsrcs[k].voltage);
        int row = n + k;
        if (a != 0)
        {
            A(row, a - 1) = Scalar(1);
            A(a - 1, row) = Scalar(1);
        }
        if (b != 0)
        {
            A(row, b - 1) = Scalar(-1);
            A(b - 1, row) = Scalar(-1);
        }
        z(row) = v;
    }
}

// Explicit instantiations
template void MNABuilder::build<double>(const NetlistParser &, Eigen::MatrixXd &, Eigen::VectorXd &);
template void MNABuilder::build<std::complex<double>>(const NetlistParser &, Eigen::MatrixXcd &, Eigen::VectorXcd &);
