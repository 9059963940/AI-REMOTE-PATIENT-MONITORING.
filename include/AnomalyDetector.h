#ifndef ANOMALY_DETECTOR_H
#define ANOMALY_DETECTOR_H

#include "PatientData.h"

class AnomalyDetector
{
public:
    bool detect(const PatientData& data);
};

#endif