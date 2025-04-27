#include "CircuitSimulator/CircuitSimulator.hpp"
#include "Utils/Benchmark.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: simulator <netlist file>\n";
        return 1;
    }

    Benchmark::start("Simulation");
    CircuitSimulator simulator(argv[1]);
    simulator.run();
    Benchmark::printAccumulated("Parsing Phase");
    Benchmark::printAccumulated("DC Phase");
    Benchmark::printAccumulated("AC Phase");
    Benchmark::stop("Simulation");

    return 0;
}
