#include "SimulationPrinter.hpp"
#include <iostream>
#include <iomanip>

namespace SimulationPrinter
{

    template <typename Scalar>
    void printSolution(const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &x, int nodeCount, const std::vector<VoltageSource> &vsrcs)
    {
        std::cout << std::scientific << std::setprecision(6); // Formatting

        std::cout << "Node Voltages:\n";
        for (int i = 0; i < nodeCount; ++i)
            std::cout << "V(" << (i + 1) << ") = " << x(i) << " V\n";

        std::cout << "Currents through Voltage Sources:\n";
        for (size_t i = 0; i < vsrcs.size(); ++i)
            std::cout << vsrcs[i].name << " current = " << x(nodeCount + i) << " A\n";
    }

    // Explicit template instantiation for VectorXd and VectorXcd
    template void printSolution<double>(const Eigen::VectorXd &x, int nodeCount, const std::vector<VoltageSource> &vsrcs);
    template void printSolution<std::complex<double>>(const Eigen::VectorXcd &x, int nodeCount, const std::vector<VoltageSource> &vsrcs);

}
