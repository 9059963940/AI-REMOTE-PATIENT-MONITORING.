#include "../include/DatabaseManager.h"
#include <sqlite3.h>
#include <iostream>

static sqlite3* db = nullptr;

DatabaseManager::DatabaseManager(const std::string& dbName)
{
    if (sqlite3_open(dbName.c_str(), &db))
    {
        std::cout << "DB Error: Unable to open database\n";
    }
}

void DatabaseManager::init()
{
    std::string sql =
        "CREATE TABLE IF NOT EXISTS patients("
        "id INT, hr INT, spo2 INT, temp REAL);";

    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << "Table creation failed: "
                  << (errMsg ? errMsg : "Unknown error") << std::endl;
    }
}

void DatabaseManager::insert(const PatientData& d)
{
    std::string sql =
        "INSERT INTO patients VALUES("
        + std::to_string(d.patientId) + ","
        + std::to_string(d.heartRate) + ","
        + std::to_string(d.spo2) + ","
        + std::to_string(d.temperature) + ");";

    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << "Insert failed: "
                  << (errMsg ? errMsg : "Unknown error") << std::endl;
    }
}