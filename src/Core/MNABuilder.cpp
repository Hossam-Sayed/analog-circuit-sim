#include "Core/MNABuilder.hpp"

void MNABuilder::buildDC(const NetlistParser &netlist,
                         Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                         Eigen::Matrix<double, Eigen::Dynamic, 1> &z)
{
    int n = netlist.getMaxNode();

    // Sum the total number of indexed components (i.e., extra variables)
    int m = 0;
    for (const auto &[type, comps] : netlist.getIndexedComponents())
        m += comps.size();

    int size = n + m;
    A = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>::Zero(size, size);
    z = Eigen::Matrix<double, Eigen::Dynamic, 1>::Zero(size);

    for (const auto &m : netlist.getMatrixStampers())
        m->stampMatrixDC(A);
    for (const auto &mv : netlist.getMatrixVectorStampers())
        mv->stampMatrixVectorDC(A, z);
    for (const auto &v : netlist.getVectorStampers())
        v->stampVectorDC(z);
}

void MNABuilder::buildAC(const NetlistParser &netlist,
                         const SimulationContext context,
                         Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic> &A,
                         Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1> &z)
{
    int n = netlist.getMaxNode();

    // Sum the total number of indexed components (i.e., extra variables)
    int m = 0;
    for (const auto &[type, comps] : netlist.getIndexedComponents())
        m += comps.size();

    int size = n + m;
    A = Eigen::Matrix<std::complex<double>, Eigen::Dynamic, Eigen::Dynamic>::Zero(size, size);
    z = Eigen::Matrix<std::complex<double>, Eigen::Dynamic, 1>::Zero(size);

    for (const auto &m : netlist.getMatrixStampers())
        m->stampMatrixAC(A, context);
    for (const auto &mv : netlist.getMatrixVectorStampers())
        mv->stampMatrixVectorAC(A, z, context);
    for (const auto &v : netlist.getVectorStampers())
        v->stampVectorAC(z, context);
}

void MNABuilder::buildTRAN(const NetlistParser &netlist,
                           const SimulationContext context,
                           Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> &A,
                           Eigen::Matrix<double, Eigen::Dynamic, 1> &z)
{
    // TODO: Start Transient logic
}