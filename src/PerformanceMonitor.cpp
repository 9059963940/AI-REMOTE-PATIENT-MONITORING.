#include "../include/PerformanceMonitor.h"

PerformanceMonitor::PerformanceMonitor()
{
    processedRecords = 0;
}

void PerformanceMonitor::increment()
{
    processedRecords++;
}

long PerformanceMonitor::getProcessed() const
{
    return processedRecords;
}