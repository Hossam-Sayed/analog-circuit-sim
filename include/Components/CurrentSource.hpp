#pragma once
#include "VectorStamperImpl.hpp"

class CurrentSource : public VectorStamperImpl<CurrentSource>
{
public:
    CurrentSource(const std::string &name, int node1, int node2, double current);

    template <typename T>
    void stamp(Vector<T> &z) const;

private:
    int node1, node2;
    double current;
};