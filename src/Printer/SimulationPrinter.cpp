#include "Printer/SimulationPrinter.hpp"
#include <iomanip>
#include <iostream>

namespace SimulationPrinter
{

    template <typename Scalar>
    void printSolution(const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &x,
                       int nodeCount,
                       int const voltageSourceCount)
    {
        std::cout << std::scientific << std::setprecision(6); // Formatting

        std::cout << "Node Voltages:\n";
        for (int i = 0; i < nodeCount; ++i)
            std::cout << "V(" << (i + 1) << ") = " << x(i) << " V\n";

        std::cout << "Currents through Voltage Sources:\n";
        for (size_t i = 0; i < voltageSourceCount; ++i)
            std::cout << "Current = " << x(nodeCount + i) << " A\n";
    }

    // Explicit template instantiation for VectorXd and VectorXcd
    template void printSolution<double>(const Eigen::VectorXd &x, int nodeCount, const int voltageSourceCount);
    template void printSolution<std::complex<double>>(const Eigen::VectorXcd &x, int nodeCount, const int voltageSourceCount);
}
