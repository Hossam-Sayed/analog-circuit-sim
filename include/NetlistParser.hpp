#pragma once
#include <string>
#include <vector>
#include "components/Components.hpp"

class NetlistParser {
public:
    bool parse(const std::string &filename);
    const std::vector<Resistor> &getResistors() const;
    const std::vector<VoltageSource> &getVoltageSources() const;
    int getMaxNode() const;

private:
    std::vector<Resistor> resistors;
    std::vector<VoltageSource> voltageSources;
    int maxNode = 0;
};
