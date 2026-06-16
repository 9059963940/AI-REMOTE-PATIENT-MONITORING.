#pragma once

#include <string>
#include <unordered_map>

class ConfigManager
{
private:
    std::unordered_map<std::string, double> config;

public:
    void load(const std::string& file);

    double get(const std::string& key);
};