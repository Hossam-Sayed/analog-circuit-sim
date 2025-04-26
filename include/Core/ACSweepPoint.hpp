#pragma once
#include <Eigen/Dense>

struct ACSweepPoint
{
    double frequency;
    Eigen::VectorXcd x;
};