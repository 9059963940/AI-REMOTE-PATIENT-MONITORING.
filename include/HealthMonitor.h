#pragma once

#include <atomic>

class HealthMonitor
{
private:
    std::atomic<int> dropped{0};

public:
    void incDrops()
    {
        dropped++;
    }

    int getDrops()
    {
        return dropped.load();
    }
};