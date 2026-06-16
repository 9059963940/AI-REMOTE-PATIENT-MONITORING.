#pragma once
struct PatientData
{
    int patientId;
    int heartRate;
    int spo2;
    float temperature;
    
    bool isEnd = false;
};