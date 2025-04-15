#include "NetlistParser.hpp"
#include "CircuitSimulator.hpp"
#include <iostream>

int main()
{
    NetlistParser parser;
    if (!parser.parse("data/example.net"))
    {
        std::cerr << "Failed to parse netlist.\n";
        return 1;
    }

    CircuitSimulator simulator(parser);
    simulator.solve();

    return 0;
}
