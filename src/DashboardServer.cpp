#include "../include/DashboardServer.h"

#include <iostream>

void Dashboard::display(const PatientData& data)
{
    std::cout
        << "Patient "
        << data.patientId
        << " | HR:"
        << data.heartRate
        << " | SPO2:"
        << data.spo2
        << " | Temp:"
        << data.temperature
        << std::endl;
}