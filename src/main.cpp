#include "../include/DataGenerator.h"
#include "../include/ThreadSafeQueue.h"
#include "../include/ZScoreDetector.h"
#include "../include/AlertManager.h"
#include "../include/Metrics.h"

#include <thread>
#include <iostream>

ThreadSafeQueue<PatientData> queue;
Metrics metrics;

void producer()
{
    DataGenerator gen;

    for (int i = 0; i < 2000; i++)
    {
        queue.push(gen.generate(i));

        std::this_thread::sleep_for(
            std::chrono::milliseconds(2));
    }
}

void consumer()
{
    ZScoreDetector detector;
    AlertManager alert;

    for (int i = 0; i < 2000; i++)
    {
        PatientData data = queue.pop();

        metrics.increment();

        if (detector.detect(data))
        {
            alert.sendAlert(data);
        }
    }
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            end - start).count();

    std::cout << "\n===== SYSTEM REPORT =====\n";

    std::cout << "Processed: "
              << metrics.getProcessed()
              << "\n";

    std::cout << "Throughput (items/sec): "
              << metrics.throughput()
              << "\n";

    std::cout << "Total runtime (ms): "
              << duration
              << "\n";

    return 0;
}