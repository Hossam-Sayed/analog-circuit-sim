#include "Core/MNABuilder.hpp"

int MNABuilder::getMatrixSize(const NetlistParser &netlist)
{
    return netlist.getMaxNode() + netlist.getIndexedComponentsCount();
}

void MNABuilder::stampDC(const NetlistParser &netlist,
                         Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                         Eigen::Matrix<double, Eigen::Dynamic, 1> &z)
{
    for (const auto &m : netlist.getMatrixStampers())
        m->stampMatrixDC(A);
    for (const auto &mv : netlist.getMatrixVectorStampers())
        mv->stampMatrixVectorDC(A, z);
    for (const auto &v : netlist.getVectorStampers())
        v->stampVectorDC(z);
}

void MNABuilder::stampAC(const NetlistParser &netlist,
                         double omega,
                         Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> &A,
                         Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1> &z)
{
    for (const auto &m : netlist.getMatrixStampers())
        m->stampMatrixAC(A, omega);
    for (const auto &mv : netlist.getMatrixVectorStampers())
        mv->stampMatrixVectorAC(A, z, omega);
    for (const auto &v : netlist.getVectorStampers())
        v->stampVectorAC(z, omega);
}

void MNABuilder::stampTRAN(const NetlistParser &netlist,
                           //    Send transParams here
                           Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                           Eigen::Matrix<double, Eigen::Dynamic, 1> &z)
{
    // TODO: Start Transient logic
}