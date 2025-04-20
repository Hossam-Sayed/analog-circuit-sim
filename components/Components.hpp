#pragma once
#include <string>

struct Resistor
{
    std::string name;
    int node1, node2;
    double resistance;
};

struct VoltageSource
{
    std::string name;
    int node1, node2;
    double voltage;
};