#include "Parser/NetlistParser.hpp"
#include "Components/Resistor.hpp"
#include "Components/VoltageSource.hpp"
#include "Components/CurrentSource.hpp"
#include "Components/Capacitor.hpp"
#include "Utils/Benchmark.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

bool NetlistParser::parse(const std::string &filename)
{
    Benchmark::accumulateStart("Parsing Phase");
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
            hasDC = true;
        else if (name == ".AC")
        {
            std::string sweepType;
            int points;
            double fStart, fStop;
            iss >> sweepType >> points >> fStart >> fStop;
            SweepType type = (sweepType == "LIN")   ? SweepType::LIN
                             : (sweepType == "DEC") ? SweepType::DEC
                                                    : SweepType::OCT;
            acParams = ACParams(type, points, fStart, fStop);
            hasAC = true;
        }
        else if (name == ".TRAN")
            hasTRAN = true;
        else if (name[0] == 'R')
        {
            int n1, n2;
            double res;
            iss >> n1 >> n2 >> res;
            n1--, n2--;
            matrixStampers.push_back(std::make_unique<Resistor>(name, n1, n2, res));
            maxNode = std::max({maxNode, n1 + 1, n2 + 1});
        }
        else if (name[0] == 'V')
        {
            int n1, n2;
            double volt;
            iss >> n1 >> n2 >> volt;
            n1--, n2--;
            auto vsrc = std::make_unique<VoltageSource>(name, n1, n2, volt);
            indexedComponents[IndexType::VoltageSource].push_back(vsrc.get());
            matrixVectorStampers.push_back(std::move(vsrc));
            maxNode = std::max({maxNode, n1 + 1, n2 + 1});
        }
        else if (name[0] == 'I')
        {
            int n1, n2;
            double i;
            iss >> n1 >> n2 >> i;
            n1--, n2--;
            maxNode = std::max({maxNode, n1, n2});
            vectorStampers.push_back(std::make_unique<CurrentSource>(name, n1, n2, i));
        }
        else if (name[0] == 'C')
        {
            int n1, n2;
            double cap;
            iss >> n1 >> n2 >> cap;
            n1--, n2--;
            matrixStampers.push_back(std::make_unique<Capacitor>(name, n1, n2, cap));
            maxNode = std::max({maxNode, n1 + 1, n2 + 1});
        }
    }

    assignIndices();
    Benchmark::accumulateStop("Parsing Phase");
    return true;
}

void NetlistParser::assignIndices()
{
    static const std::vector<IndexType> orderedTypes = {
        IndexType::VoltageSource,
        IndexType::VCVS,
        IndexType::CCVS,
        IndexType::CCCS,
        IndexType::Inductor,
    };

    int globalOffset = maxNode;
    for (IndexType type : orderedTypes)
    {
        auto &vec = indexedComponents[type];
        indexedComponentsCount += vec.size();
        for (auto *comp : vec)
            comp->setIndex(globalOffset++);
    }
}

const MatrixStampersList &NetlistParser::getMatrixStampers() const { return matrixStampers; }

const MatrixVectorStampersList &NetlistParser::getMatrixVectorStampers() const { return matrixVectorStampers; }

const VectorStampersList &NetlistParser::getVectorStampers() const { return vectorStampers; }

const int &NetlistParser::getMaxNode() const { return maxNode; }

const int &NetlistParser::getIndexedComponentsCount() const { return indexedComponentsCount; }

const IndexedComponentsMap &NetlistParser::getIndexedComponents() const { return indexedComponents; }

const bool &NetlistParser::getHasDC() const { return hasDC; }

const bool &NetlistParser::getHasAC() const { return hasAC; }

const bool &NetlistParser::getHasTRAN() const { return hasTRAN; }

const bool &NetlistParser::getIsLinear() const { return isLinear; }

const ACParams &NetlistParser::getACParams() const { return acParams; }