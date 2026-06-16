#include "../include/ConfigManager.h"
#include <fstream>
#include <sstream>

void ConfigManager::load(const std::string& file)
{
    std::ifstream in(file);
    std::string key;
    double value;

    while(in >> key >> value)
    {
        config[key] = value;
    }
}

double ConfigManager::get(const std::string& key)
{
    return config[key];
}