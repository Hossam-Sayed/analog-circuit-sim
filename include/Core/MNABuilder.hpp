#pragma once
#include "Parser/NetlistParser.hpp"
#include <Eigen/Dense>

class MNABuilder
{
public:
    template <typename Scalar>
    static void build(const NetlistParser &netlist,
                      Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> &A,
                      Eigen::Matrix<Scalar, Eigen::Dynamic, 1> &z);
};