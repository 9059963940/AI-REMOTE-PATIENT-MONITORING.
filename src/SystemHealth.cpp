#include "../include/SystemHealth.h"

SystemHealth::SystemHealth()
{
    cpuHealthy = true;
    memoryHealthy = true;
    queueHealthy = true;
}

void SystemHealth::updateQueueStatus(bool ok)
{
    queueHealthy = ok;
}

bool SystemHealth::isSystemHealthy()
{
    return cpuHealthy && memoryHealthy && queueHealthy;
}