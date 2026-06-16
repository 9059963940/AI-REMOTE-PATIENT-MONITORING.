#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    json patient =
    {
        {"id",1},
        {"heartRate",85},
        {"spo2",98}
    };

    std::cout << patient.dump(4) << std::endl;

    return 0;
}