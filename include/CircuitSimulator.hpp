#pragma once
#include "NetlistParser.hpp"
#include <vector>

class CircuitSimulator
{
public:
    CircuitSimulator(const NetlistParser &parser);
    void solve();

private:
    const NetlistParser &netlist;
};
