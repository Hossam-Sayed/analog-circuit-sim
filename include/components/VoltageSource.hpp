#pragma once
#include <string>

struct VoltageSource
{
    std::string name;
    int node1, node2;
    double voltage;
};