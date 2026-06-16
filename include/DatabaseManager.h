#pragma once

#include "PatientData.h"
#include <string>

class DatabaseManager
{
public:
    DatabaseManager(const std::string& dbName);

    void init();
    void insert(const PatientData& data);
};