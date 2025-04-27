#include "Utils/Benchmark.hpp"

void Benchmark::start(const std::string &label)
{
    startTimes[label] = Clock::now();
}

void Benchmark::stop(const std::string &label)
{
    auto end = Clock::now();

    auto it = startTimes.find(label);
    if (it != startTimes.end())
    {
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - it->second).count();
        std::cout << "[Benchmark] " << label << ": " << duration << " microseconds\n";
        startTimes.erase(it);
    }
    else
    {
        std::cerr << "[Benchmark] Warning: No start() call found for label \"" << label << "\"\n";
    }
}

void Benchmark::accumulateStart(const std::string &label)
{
    accumulations[label].lastStart = Clock::now();
}

void Benchmark::accumulateStop(const std::string &label)
{
    auto end = Clock::now();
    auto &acc = accumulations[label];
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - acc.lastStart).count();
    acc.totalMicroseconds += duration;
    acc.count++;
}

void Benchmark::printAccumulated(const std::string &label)
{
    auto it = accumulations.find(label);
    if (it != accumulations.end())
    {
        const auto &acc = it->second;
        double average = static_cast<double>(acc.totalMicroseconds) / acc.count;
        std::cout << "[Benchmark] " << label
                  << ": total = " << acc.totalMicroseconds
                  << " microseconds, count = " << acc.count
                  << ", average = " << average << " microseconds\n";
    }
    else
    {
        std::cerr << "[Benchmark] Warning: No accumulated data for label \"" << label << "\"\n";
    }
}

void Benchmark::printAllAccumulated()
{
    for (auto acc : accumulations)
    {
        const auto &value = acc.second;
        double average = static_cast<double>(value.totalMicroseconds) / value.count;
        std::cout << "[Benchmark] " << acc.first
                  << ": total = " << value.totalMicroseconds
                  << " microseconds, count = " << value.count
                  << ", average = " << average << " microseconds\n";
    }
}

// AutoTimer Implementation
AutoTimer::AutoTimer(const std::string &label) : label(label), startTime(Clock::now()) {}

AutoTimer::~AutoTimer()
{
    auto endTime = Clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "[Benchmark] " << label << ": " << duration << " microseconds (AutoTimer)\n";
}
