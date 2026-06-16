cmake_minimum_required(VERSION 3.10)

project(RemotePatientMonitoring)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(Threads REQUIRED)

add_executable(RemotePatientMonitoring
    src/main.cpp
    src/DataGenerator.cpp
    src/ZScoreDetector.cpp
    src/AlertManager.cpp
    src/PerformanceMonitor.cpp
    src/CsvLoader.cpp
    src/Metrics.cpp
)

target_link_libraries(RemotePatientMonitoring
    Threads::Threads
)