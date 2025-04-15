#include "CircuitSimulator.hpp"
#include <iostream>

CircuitSimulator::CircuitSimulator(const NetlistParser &parser) : netlist(parser) {}

void CircuitSimulator::solve()
{
    std::cout << "Solving circuit with "
              << netlist.getResistors().size() << " resistors and "
              << netlist.getVoltageSources().size() << " voltage sources.\n";
}
