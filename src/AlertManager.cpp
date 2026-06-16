#include "../include/AlertManager.h"

#include <fstream>
#include <iostream>

void AlertManager::sendAlert(const PatientData& data)
{
    std::ofstream file("logs/alerts.txt",std::ios::app);

    file
        << "Patient "
        << data.patientId
        << " ALERT "
        << "HR="
        << data.heartRate
        << " SPO2="
        << data.spo2
        << " TEMP="
        << data.temperature
        << "\n";

    std::cout
        << "[ALERT] Patient "
        << data.patientId
        << std::endl;
}