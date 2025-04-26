#include "Simulation/ACAnalysis.hpp"
#include "Core/LinearSolver.hpp"
#include "Printer/SimulationPrinter.hpp"
#include <iostream>

void ACAnalysis::run(const NetlistParser &netlist)
{
    // Currently, it handles only linear analysis
    std::cout << "[AC Analysis] Running...\n";
    auto results = LinearSolver::solveAC(netlist);
    SimulationPrinter::printACSweep(results,
                                    netlist.getMaxNode(),
                                    netlist.getIndexedComponents());
}