#include "Simulation/ACParams.hpp"

ACParams::ACParams(SweepType sweepType,
                   int numPoints,
                   double fStart,
                   double fStop)
    : sweepType(sweepType), numPoints(numPoints), fStart(fStart), fStop(fStop)
{
    calcFrequencies();
}

void ACParams::calcFrequencies()
{
    if (sweepType == SweepType::LIN)
    {
        double step = (fStop - fStart) / (numPoints - 1);
        for (int i = 0; i < numPoints; ++i)
            freqs.push_back(fStart + i * step);
    }
    else if (sweepType == SweepType::DEC)
    {
        double decadeStep = std::pow(10.0, 1.0 / (numPoints - 1));
        for (double f = fStart; f <= fStop; f *= decadeStep)
            freqs.push_back(f);
    }
    else if (sweepType == SweepType::OCT)
    {
        double octaveStep = std::pow(2.0, 1.0 / (numPoints - 1));
        for (double f = fStart; f <= fStop; f *= octaveStep)
            freqs.push_back(f);
    }
}

const std::vector<double> &ACParams::getFrequencies() const { return freqs; }