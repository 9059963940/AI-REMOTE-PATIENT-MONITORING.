#pragma once

#include "PatientData.h"

#include <vector>

class CsvLoader
{
public:

    std::vector<PatientData> load(const std::string& filename);
};