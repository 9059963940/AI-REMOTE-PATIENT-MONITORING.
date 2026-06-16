#pragma once

#include "Metrics.h"

class HttpServer
{
private:
    Metrics* metrics;
    bool running;

public:
    HttpServer();

    void start(Metrics* m);
    void stop();
};