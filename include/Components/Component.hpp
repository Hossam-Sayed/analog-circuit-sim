#pragma once
#include <Eigen/Dense>
#include <complex>
#include <memory>
#include <string>

template <typename Scalar>
using Matrix = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>;

template <typename Scalar>
using Vector = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;

// Base interface for all components
class Component
{
public:
    virtual ~Component() = default;

    const std::string &getName() const { return name; }
    void setName(const std::string &n) { name = n; }

protected:
    std::string name;
};
