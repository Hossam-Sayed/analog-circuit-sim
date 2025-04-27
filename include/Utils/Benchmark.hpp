#pragma once

#include <chrono>
#include <string>
#include <unordered_map>
#include <iostream>

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Benchmark
{
public:
    static void start(const std::string &label);
    static void stop(const std::string &label);

    // Accumulation API
    static void accumulateStart(const std::string &label);
    static void accumulateStop(const std::string &label);
    static void printAccumulated(const std::string &label);
    static void printAllAccumulated();

private:
    struct Accumulator
    {
        long long totalMicroseconds = 0;
        size_t count = 0;
        TimePoint lastStart;
    };

    static inline std::unordered_map<std::string, TimePoint> startTimes;
    static inline std::unordered_map<std::string, Accumulator> accumulations;
};

class AutoTimer
{
public:
    explicit AutoTimer(const std::string &label);
    ~AutoTimer();

private:
    std::string label;
    TimePoint startTime;
};
