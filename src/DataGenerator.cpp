#include "../include/DataGenerator.h"

#include <random>

PatientData DataGenerator::generate(int id)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> hr(55,140);
    std::uniform_int_distribution<> spo2(85,100);
    std::uniform_real_distribution<> temp(96.0,104.0);

    PatientData data;

    data.patientId=id;
    data.heartRate=hr(gen);
    data.spo2=spo2(gen);
    data.temperature=temp(gen);

    return data;
}