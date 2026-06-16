#pragma once

class PerformanceMonitor
{
private:
    long processedRecords;

public:
    PerformanceMonitor();

    void increment();

    long getProcessed() const;
};