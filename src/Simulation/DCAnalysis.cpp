#include "Simulation/DCAnalysis.hpp"
#include "Core/LinearSolver.hpp"
#include "Printer/SimulationPrinter.hpp"
#include <iostream>

void DCAnalysis::run(const NetlistParser &netlist)
{
    // Currently, it handles only linear analysis
    std::cout << "[DC Analysis] Running...\n";
    auto result = LinearSolver::solveDC(netlist);
    SimulationPrinter::printSolution(result,
                                     netlist.getMaxNode(),
                                     netlist.getIndexedComponents());
}