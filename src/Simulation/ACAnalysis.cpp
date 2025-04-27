#include "Simulation/ACAnalysis.hpp"
#include "Core/LinearSolver.hpp"
#include "Printer/SimulationPrinter.hpp"
#include "Utils/Benchmark.hpp"
#include <iostream>

void ACAnalysis::run(const NetlistParser &netlist)
{
    Benchmark::accumulateStart("AC Phase");
    // Currently, it handles only linear analysis
    std::cout << "[AC Analysis] Running...\n";
    auto results = LinearSolver::solveAC(netlist);
    SimulationPrinter::printACSweep(results,
                                    netlist.getMaxNode(),
                                    netlist.getIndexedComponents());
    Benchmark::accumulateStop("AC Phase");
}