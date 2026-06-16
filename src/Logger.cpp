#include "Logger.h"

#include <fstream>

void Logger::log(const std::string& msg)
{
    std::ofstream file("logs/system.log", std::ios::app);

    file << msg << std::endl;
}