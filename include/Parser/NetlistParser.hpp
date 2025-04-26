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
#include "Simulation/ACParams.hpp"

using MatrixStampersList = std::vector<std::unique_ptr<MatrixStamper>>;
using MatrixVectorStampersList = std::vector<std::unique_ptr<MatrixVectorStamper>>;
using VectorStampersList = std::vector<std::unique_ptr<VectorStamper>>;
using IndexedComponentsMap = std::unordered_map<IndexType, std::vector<IndexedComponent *>>;

class NetlistParser
{
public:
    bool parse(const std::string &filename);
    void assignIndices();

    const MatrixStampersList &getMatrixStampers() const;
    const MatrixVectorStampersList &getMatrixVectorStampers() const;
    const VectorStampersList &getVectorStampers() const;
    const IndexedComponentsMap &getIndexedComponents() const;

    const int &getMaxNode() const;
    const int &getIndexedComponentsCount() const;

    const bool &getHasDC() const;
    const bool &getHasAC() const;
    const bool &getHasTRAN() const;
    const bool &getIsLinear() const;

    const ACParams &getACParams() const;

private:
    MatrixStampersList matrixStampers;
    MatrixVectorStampersList matrixVectorStampers;
    VectorStampersList vectorStampers;
    IndexedComponentsMap indexedComponents;

    bool hasDC = false, hasAC = false, hasTRAN = false, isLinear = true;

    int maxNode = 0, indexedComponentsCount = 0;

    ACParams acParams;
};