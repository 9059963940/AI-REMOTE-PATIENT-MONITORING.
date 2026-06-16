#pragma once
#include "PatientData.h"
#include <string>

class JsonExporter
{
public:
    std::string convert(const PatientData& data);
};