#pragma once

#include "PatientData.h"

class AlertManager
{
public:
    void sendAlert(const PatientData& data);
};