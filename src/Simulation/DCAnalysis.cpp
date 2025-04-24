#include "Simulation/DCAnalysis.hpp"
#include "Core/LinearSolver.hpp"
#include "Printer/SimulationPrinter.hpp"

void DCAnalysis::run(const NetlistParser &netlist)
{
    // Currently, it handles only linear analysis
    auto result = LinearSolver::solveDC(netlist);
    SimulationPrinter::printSolution(result,
                                     netlist.getMaxNode(),
                                     netlist.getIndexedComponentCount(IndexType::VoltageSource));
}