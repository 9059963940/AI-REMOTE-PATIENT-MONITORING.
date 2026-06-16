#pragma once
#include "PatientData.h"
#include <deque>

class ZScoreDetector
{
private:
    std::deque<int> window;
    int windowSize;

public:
    ZScoreDetector(int size = 10);

    bool detect(const PatientData& data);
};