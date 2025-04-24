#pragma once
#include <Eigen/Dense>
#include <complex>
#include <memory>

template <typename Scalar>
using Matrix = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>;

template <typename Scalar>
using Vector = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;

// Base interface for all components
class Component
{
public:
    virtual ~Component() = default;
};