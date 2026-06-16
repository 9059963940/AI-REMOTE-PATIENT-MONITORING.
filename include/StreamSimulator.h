#pragma once

#include "ThreadSafeQueue.h"
#include "PatientData.h"

class StreamSimulator
{
private:
    ThreadSafeQueue<PatientData>& queue;

public:
    StreamSimulator(ThreadSafeQueue<PatientData>& q);

    void start();
};