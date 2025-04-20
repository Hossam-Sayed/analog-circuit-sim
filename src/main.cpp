#include "CircuitSimulator.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: simulator <netlist file>\n";
        return 1;
    }

    CircuitSimulator simulator(argv[1]);
    simulator.run();

    return 0;
}
