#include "../include/StreamSimulator.h"
#include "../include/DataGenerator.h"
#include <thread>
#include <chrono>

StreamSimulator::StreamSimulator(ThreadSafeQueue<PatientData>& q)
    : queue(q) {}

void StreamSimulator::start()
{
    DataGenerator generator;

    for(int i = 0; i < 1000; i++)
    {
        queue.push(generator.generate(i));

        std::this_thread::sleep_for(
            std::chrono::milliseconds(5));
    }
}