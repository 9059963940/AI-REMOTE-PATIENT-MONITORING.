#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

#include "PatientData.h"

class AlertManager
{
public:
    void sendAlert(const PatientData& data);
};

#endif