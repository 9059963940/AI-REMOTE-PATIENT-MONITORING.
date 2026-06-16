#include "../include/JsonConverter.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string JsonConverter::toJson(const PatientData& d)
{
    json j;

    j["id"] = d.patientId;
    j["heartRate"] = d.heartRate;
    j["spo2"] = d.spo2;
    j["temperature"] = d.temperature;

    return j.dump();
}