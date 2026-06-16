#pragma once

#include <chrono>

class Metrics
{
private:
    long processedRecords;
    std::chrono::steady_clock::time_point startTime;

public:
    Metrics();

    void increment();

    long getProcessed();

    double throughput();
};