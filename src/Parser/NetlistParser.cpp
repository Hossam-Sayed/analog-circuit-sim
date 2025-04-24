#include "Parser/NetlistParser.hpp"
#include "Components/Resistor.hpp"
#include "Components/VoltageSource.hpp"
// Add other component includes here (e.g., CurrentSource, Capacitor, etc.)

#include <fstream>
#include <sstream>
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
            simType = SimulationType::OP;
        else if (name == ".AC")
            simType = SimulationType::AC;
        else if (name == ".TRAN")
            simType = SimulationType::TRAN;
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
        // Add similar logic for current sources, capacitors, inductors, etc.
    }

    assignIndices();
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
        for (auto *comp : vec)
            comp->setIndex(globalOffset++);
    }
}

const std::vector<std::unique_ptr<MatrixStamper>> &NetlistParser::getMatrixStampers() const
{
    return matrixStampers;
}

const std::vector<std::unique_ptr<MatrixVectorStamper>> &NetlistParser::getMatrixVectorStampers() const
{
    return matrixVectorStampers;
}

const std::vector<std::unique_ptr<VectorStamper>> &NetlistParser::getVectorStampers() const
{
    return vectorStampers;
}

int NetlistParser::getMaxNode() const
{
    return maxNode;
}

SimulationType NetlistParser::getSimulationType() const
{
    return simType;
}

const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &NetlistParser::getIndexedComponents() const
{
    return indexedComponents;
}

int NetlistParser::getIndexedComponentCount(IndexType type) const
{
    auto it = indexedComponents.find(type);
    return (it != indexedComponents.end()) ? static_cast<int>(it->second.size()) : 0;
}
