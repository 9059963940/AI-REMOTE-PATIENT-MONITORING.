#include "../include/DataGenerator.h"
#include "../include/AnomalyDetector.h"
#include "../include/AlertManager.h"
#include "../include/Dashboard.h"

#include <thread>
#include <chrono>

int main()
{
    DataGenerator generator;
    AnomalyDetector detector;
    AlertManager alert;
    Dashboard dashboard;

    for(int i=1;i<=1000;i++)
    {
        PatientData data =
            generator.generate(i);

        dashboard.display(data);

        if(detector.detect(data))
        {
            alert.sendAlert(data);
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(50));
    }

    return 0;
}