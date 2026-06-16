#pragma once
#include "PatientData.h"
#include <string>

class JsonConverter
{
public:
    std::string toJson(const PatientData& data);
};