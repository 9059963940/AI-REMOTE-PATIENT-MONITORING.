#include "../include/ZScoreDetector.h"
#include <cassert>

int main()
{
    ZScoreDetector detector;

    PatientData patient;

    patient.patientId = 1;
    patient.heartRate = 150;
    patient.spo2 = 85;
    patient.temperature = 102;

    bool isAnomaly = detector.detect(patient);

    assert(isAnomaly == true);

    return 0;
}