#include "../include/ZScoreDetector.h"
#include <cmath>

ZScoreDetector::ZScoreDetector(int size)
{
    windowSize = size;
}

bool ZScoreDetector::detect(const PatientData& data)
{
    window.push_back(data.heartRate);

    if (window.size() > windowSize)
        window.pop_front();

    if (window.size() < 5)
        return false;

    double mean = 0;
    for (auto v : window)
        mean += v;

    mean /= window.size();

    double variance = 0;
    for (auto v : window)
        variance += (v - mean) * (v - mean);

    variance /= window.size();

    double stddev = sqrt(variance);

    if (stddev == 0)
        return false;

    double z = (data.heartRate - mean) / stddev;

    return std::abs(z) > 2.5;
}