#include "../include/JsonExporter.h"

std::string JsonExporter::convert(const PatientData& data)
{
    return "{ \"id\": " + std::to_string(data.patientId) +
           ", \"hr\": " + std::to_string(data.heartRate) +
           ", \"spo2\": " + std::to_string(data.spo2) +
           ", \"temp\": " + std::to_string(data.temperature) +
           " }";
}