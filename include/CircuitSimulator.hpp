#pragma once
#include "NetlistParser.hpp"
#include <Eigen/SparseLU>

class CircuitSimulator
{
public:
    CircuitSimulator(const NetlistParser &parser);
    void solve();

private:
    const NetlistParser &netlist;
    void constructMNASystem(Eigen::MatrixXd &A, Eigen::VectorXd &z);
    void print(Eigen::VectorXd x, int n);
};
