#include "../include/AnomalyDetector.h"

bool AnomalyDetector::detect(const PatientData& data)
{
    if(data.heartRate > 120)
        return true;

    if(data.spo2 < 90)
        return true;

    if(data.temperature > 101.0)
        return true;

    return false;
}