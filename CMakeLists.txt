cmake_minimum_required(VERSION 3.10)

project(RemotePatientMonitoring)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    RemotePatientMonitoring

    src/main.cpp
    src/DataGenerator.cpp
    src/AnomalyDetector.cpp
    src/AlertManager.cpp
    src/Dashboard.cpp
)