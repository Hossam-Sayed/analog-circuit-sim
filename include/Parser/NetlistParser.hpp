#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "Components/Component.hpp"
#include "Components/MatrixStamper.hpp"
#include "Components/MatrixVectorStamper.hpp"
#include "Components/VectorStamper.hpp"
#include "Components/IndexedComponent.hpp"
#include "Common/IndexType.hpp"
#include "Common/SimulationType.hpp"

class NetlistParser
{
public:
    bool parse(const std::string &filename);
    void assignIndices();

    const std::vector<std::unique_ptr<MatrixStamper>> &getMatrixStampers() const;
    const std::vector<std::unique_ptr<MatrixVectorStamper>> &getMatrixVectorStampers() const;
    const std::vector<std::unique_ptr<VectorStamper>> &getVectorStampers() const;
    int getMaxNode() const;
    SimulationType getSimulationType() const;
    const std::unordered_map<IndexType, std::vector<IndexedComponent *>> &getIndexedComponents() const;
    int getIndexedComponentCount(IndexType type) const;

private:
    std::vector<std::unique_ptr<MatrixStamper>> matrixStampers;
    std::vector<std::unique_ptr<MatrixVectorStamper>> matrixVectorStampers;
    std::vector<std::unique_ptr<VectorStamper>> vectorStampers;

    std::unordered_map<IndexType, std::vector<IndexedComponent *>> indexedComponents;

    int maxNode = 0;
    SimulationType simType = SimulationType::NONE;
};