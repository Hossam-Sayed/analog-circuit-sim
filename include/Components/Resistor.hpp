#pragma once
#include "MatrixStamperImpl.hpp"

class Resistor : public MatrixStamperImpl<Resistor>
{
public:
    Resistor(const std::string &name, int n1, int n2, double resistance);

    template <typename T>
    void stamp(Matrix<T> &A) const;

private:
    std::string name;
    int node1, node2;
    double resistance;
};