#include "../include/DataGenerator.h"
#include <random>

PatientData DataGenerator::generate(int id)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // NORMAL range (majority cases)
    std::uniform_int_distribution<> normal_hr(60, 90);
    std::uniform_int_distribution<> normal_spo2(95, 100);
    std::uniform_real_distribution<> normal_temp(97.0, 99.5);

    // RARE abnormal spikes
    std::uniform_int_distribution<> risk_case(1, 10);

    PatientData data;

    data.patientId = id;

    if (risk_case(gen) <= 2) // 20% abnormal cases
    {
        std::uniform_int_distribution<> bad_hr(110, 160);
        std::uniform_int_distribution<> bad_spo2(80, 92);
        std::uniform_real_distribution<> bad_temp(100.0, 104.0);

        data.heartRate = bad_hr(gen);
        data.spo2 = bad_spo2(gen);
        data.temperature = bad_temp(gen);
    }
    else
    {
        data.heartRate = normal_hr(gen);
        data.spo2 = normal_spo2(gen);
        data.temperature = normal_temp(gen);
    }

    return data;
}