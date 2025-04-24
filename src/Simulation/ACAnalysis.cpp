#include "Simulation/ACAnalysis.hpp"
#include "Core/LinearSolver.hpp"
#include "Printer/SimulationPrinter.hpp"

void ACAnalysis::run(const NetlistParser &netlist)
{
    // Currently, it handles only linear analysis
    auto result = LinearSolver::solveAC(netlist);
    SimulationPrinter::printSolution(result,
                                     netlist.getMaxNode(),
                                     netlist.getIndexedComponentCount(IndexType::VoltageSource));
}