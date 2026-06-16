#pragma once

class SystemHealth
{
private:
    bool cpuHealthy;
    bool memoryHealthy;
    bool queueHealthy;

public:
    SystemHealth();

    void updateQueueStatus(bool ok);

    bool isSystemHealthy();
};