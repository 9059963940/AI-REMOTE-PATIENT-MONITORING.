#include "../include/CsvLoader.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::vector<PatientData>
CsvLoader::load(const std::string& filename)
{
    std::vector<PatientData> patients;

    std::ifstream file(filename);

    if(!file.is_open())
    {
        std::cout
            << "ERROR: Cannot open file: "
            << filename
            << std::endl;

        return patients;
    }

    std::string line;

    getline(file,line);

    while(getline(file,line))
    {
        std::stringstream ss(line);

        std::string token;

        PatientData p;

        getline(ss,token,',');
        p.patientId = std::stoi(token);

        getline(ss,token,',');
        p.heartRate = std::stoi(token);

        getline(ss,token,',');
        p.spo2 = std::stoi(token);

        getline(ss,token,',');
        p.temperature = std::stof(token);

        patients.push_back(p);
    }

    std::cout
        << "CSV Loaded: "
        << patients.size()
        << " patients"
        << std::endl;

    return patients;
}