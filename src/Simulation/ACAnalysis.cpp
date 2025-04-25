#include "Simulation/ACAnalysis.hpp"
#include "Core/LinearSolver.hpp"
#include "Printer/SimulationPrinter.hpp"
#include <iostream>

void ACAnalysis::run(const NetlistParser &netlist)
{
    // Currently, it handles only linear analysis
    std::cout << "[AC Analysis] Running...\n";
    SimulationContext ctx;
    ctx.type = SimulationType::AC;
    // TODO: Add other AC parameters (omega)
    // ctx.omega = netlist.omega;
    auto result = LinearSolver::solveAC(netlist, ctx);
    SimulationPrinter::printSolution(result,
                                     netlist.getMaxNode(),
                                     netlist.getIndexedComponents());
}