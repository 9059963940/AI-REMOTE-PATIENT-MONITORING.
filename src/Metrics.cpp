#include "../include/Metrics.h"

Metrics::Metrics()
{
    processedRecords = 0;
    startTime = std::chrono::steady_clock::now();
}

void Metrics::increment()
{
    processedRecords++;
}

long Metrics::getProcessed()
{
    return processedRecords;
}

double Metrics::throughput()
{
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> duration = end - startTime;

    if (duration.count() == 0)
        return 0;

    return processedRecords / duration.count();
}