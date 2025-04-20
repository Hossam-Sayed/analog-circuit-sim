#include "NetlistParser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool NetlistParser::parse(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '*')
            continue;

        std::istringstream iss(line);
        std::string name;
        iss >> name;

        if (name == ".OP")
        {
            simType = SimulationType::OP;
        }
        else if (name == ".AC")
        {
            simType = SimulationType::AC;
        }
        else if (name == ".TRAN")
        {
            simType = SimulationType::TRAN;
        }
        else if (name[0] == 'R')
        {
            int n1, n2;
            double res;
            iss >> n1 >> n2 >> res;
            resistors.push_back({name, n1, n2, res});
            maxNode = std::max({maxNode, n1, n2});
        }
        else if (name[0] == 'V')
        {
            int n1, n2;
            double volt;
            iss >> n1 >> n2 >> volt;
            voltageSources.push_back({name, n1, n2, volt});
            maxNode = std::max({maxNode, n1, n2});
        }
    }

    return true;
}

const std::vector<Resistor> &NetlistParser::getResistors() const
{
    return resistors;
}

const std::vector<VoltageSource> &NetlistParser::getVoltageSources() const
{
    return voltageSources;
}

int NetlistParser::getMaxNode() const
{
    return maxNode;
}

SimulationType NetlistParser::getSimulationType() const
{
    return simType;
}