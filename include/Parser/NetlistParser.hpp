#pragma once
#include <string>
#include <vector>
#include "Components/Components.hpp"

enum class SimulationType
{
    OP,
    AC,
    TRAN,
    NONE
};

class NetlistParser
{
public:
    bool parse(const std::string &filename);
    const std::vector<Resistor> &getResistors() const;
    const std::vector<VoltageSource> &getVoltageSources() const;
    int getMaxNode() const;
    SimulationType getSimulationType() const;

private:
    std::vector<Resistor> resistors;
    std::vector<VoltageSource> voltageSources;
    SimulationType simType = SimulationType::NONE;
    int maxNode = 0;
};