#pragma once
#include <string>
#include <iostream>
#include "NetlistParser.hpp"

class CircuitSimulator
{
public:
    CircuitSimulator(const std::string &netlistFile);
    void run(); // chooses simulation type and solves

private:
    NetlistParser parser;

    void solveOperatingPoint();
    void solveAC(); // stub for future
};
