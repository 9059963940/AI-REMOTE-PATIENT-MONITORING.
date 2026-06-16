#include "../include/HttpServer.h"

#include <iostream>
#include <thread>
#include <chrono>

// Constructor
HttpServer::HttpServer()
{
    metrics = nullptr;
    running = false;
}

// Start server (runs in background loop)
void HttpServer::start(Metrics* m)
{
    metrics = m;

    if (!metrics)
    {
        std::cerr << "[HttpServer] Error: Metrics is null!\n";
        return;
    }

    running = true;

    std::cout << "HTTP Server started on http://localhost:8080\n";

    // Simulated live dashboard loop
    while (running)
    {
        std::cout << "\n========== LIVE DASHBOARD ==========\n";

        std::cout << "Processed Records : "
                  << metrics->getProcessed() << "\n";

        std::cout << "Anomalies Detected: "
                  << metrics->getAnomalies() << "\n";

        std::cout << "Alerts Sent       : "
                  << metrics->getAlerts() << "\n";

        std::cout << "Throughput        : "
                  << metrics->getThroughput()
                  << " records/sec\n";

        std::cout << "====================================\n";

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

// Stop server safely
void HttpServer::stop()
{
    running = false;
    std::cout << "HTTP Server stopped.\n";
}