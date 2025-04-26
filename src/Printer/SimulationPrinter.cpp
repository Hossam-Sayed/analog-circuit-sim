#include "Printer/SimulationPrinter.hpp"
#include <iomanip>
#include <iostream>
#include <map>

namespace SimulationPrinter
{
    template <typename Scalar>
    void printSolution(const Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &x,
                       int nodeCount,
                       const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &indexedComponents)
    {
        std::cout << std::scientific << std::setprecision(6);

        // 1. Print node voltages
        std::cout << "Node Voltages:\n";
        for (int i = 0; i < nodeCount; ++i)
            std::cout << "V(" << (i + 1) << ") = " << x(i) << " V\n";

        // 2. Print branch currents in gold-standard order
        static const std::vector<std::pair<IndexType, std::string>> orderedPrint = {
            {IndexType::VoltageSource, "Current through Voltage Source"},
            {IndexType::VCVS, "Current through VCVS"},
            {IndexType::CCVS, "Current through CCVS"},
            {IndexType::CCCS, "Current through CCCS"},
            {IndexType::Inductor, "Current through Inductor"},
        };

        for (const auto &[type, label] : orderedPrint)
        {
            auto it = indexedComponents.find(type);
            if (it != indexedComponents.end() && !it->second.empty())
            {
                std::cout << label << ":\n";
                for (auto *comp : it->second)
                {
                    int idx = comp->getIndex();
                    std::cout << comp->getName() << "#branch = " << x(idx) << " A\n";
                }
            }
        }
    }

    void printACSweep(const std::vector<ACSweepPoint> &results,
                      int nodeCount,
                      const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &indexedComponents)
    {
        std::cout << std::fixed << std::setprecision(4);

        for (const auto &res : results)
        {
            std::cout << "\n===============================\n";
            std::cout << "Frequency = " << res.frequency << " Hz\n";
            std::cout << "===============================\n";

            printSolution<std::complex<double>>(res.x, nodeCount, indexedComponents);
        }
    }

    // Explicit instantiation
    template void printSolution<double>(
        const Eigen::VectorXd &x,
        int nodeCount,
        const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &indexedComponents);

    template void printSolution<std::complex<double>>(
        const Eigen::VectorXcd &x,
        int nodeCount,
        const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &indexedComponents);
}
