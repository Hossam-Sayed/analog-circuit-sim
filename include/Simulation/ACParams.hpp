#pragma once
#include "Common/SweepType.hpp"
#include <vector>
#include <complex>

class ACParams
{
public:
    ACParams() {}
    ACParams(SweepType sweepType, int numPoints, double fStart, double fStop);

    const std::vector<double> &getFrequencies() const;

private:
    SweepType sweepType = SweepType::LIN;
    int numPoints = 0;
    double fStart = 0, fStop = 0;
    std::vector<double> freqs;

    void calcFrequencies();
};