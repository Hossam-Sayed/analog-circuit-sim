#include "CircuitSimulator.hpp"
#include "SimulationPrinter.hpp"
#include "LinearSolver.hpp"
#include "NetlistParser.hpp"

CircuitSimulator::CircuitSimulator(const std::string &netlistFile)
{
    if (!parser.parse(netlistFile))
    {
        std::cerr << "Failed to parse netlist.\n";
        exit(1);
    }
}

void CircuitSimulator::run()
{
    switch (parser.getSimulationType())
    {
    case SimulationType::OP:
        solveOperatingPoint();
        break;
    case SimulationType::AC:
        solveAC();
        break;
    case SimulationType::TRAN:
        std::cerr << "Transient analysis not implemented yet.\n";
        break;
    default:
        std::cerr << "Unknown or missing simulation directive.\n";
    }
}

void CircuitSimulator::solveOperatingPoint()
{
    auto result = LinearSolver::solveDC(parser);
    SimulationPrinter::printSolution(result, parser.getMaxNode(), parser.getVoltageSources());
}

void CircuitSimulator::solveAC()
{
    auto result = LinearSolver::solveAC(parser);
    SimulationPrinter::printSolution(result, parser.getMaxNode(), parser.getVoltageSources());
}
