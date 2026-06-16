Remote Patient Monitoring System (C++)

A real-time multi-threaded backend system built in modern C++ that simulates continuous patient health monitoring, detects anomalies, generates alerts, and tracks system performance.

--Features
- Real-time patient data simulation (heart rate, SpO2, temperature)
- Multi-threaded Producer–Consumer architecture
- Thread-safe queue using mutex and condition variables
- Rule-based anomaly detection system
- Real-time alert generation
- Performance tracking (throughput & processed records)
- High-speed processing (~2000 records simulation)

--System Design
Producer → Thread-Safe Queue → Consumer → Anomaly Detection → Alert System → Performance Monitor


--Tech Stack
- Language: C++17
- Concurrency: std::thread, mutex, condition_variable
- Build System: CMake
- Platform: macOS / Linux
- IDE: VS Code

--Project Structure
include/
PatientData.h
DataGenerator.h
AnomalyDetector.h
AlertManager.h
ThreadSafeQueue.h
PerformanceMonitor.h

src/
main.cpp
DataGenerator.cpp
AnomalyDetector.cpp
AlertManager.cpp
PerformanceMonitor.cpp

logs/
alerts.txt


--How It Works

1. Data Generation
Simulates patient vitals like:
- Heart Rate
- SpO2
- Temperature

2. Producer–Consumer Model
- Producer generates data continuously
- Consumer processes data in real-time

3. Thread-Safe Queue
Ensures safe communication between threads without data loss.

4. Anomaly Detection
Triggers alerts when:
- Heart rate is too high
- SpO2 drops below threshold
- Abnormal physiological values detected

5. Alert System
Logs and displays alerts in real-time.

6. Performance Monitoring
Tracks:
- Total processed records
- System throughput (items/second)
- Execution time


--Sample Output
[ALERT] Patient 1946
[ALERT] Patient 1964
[ALERT] Patient 1999

==SYSTEM REPORT ===
Processed: 2000
Throughput (items/sec): 394.982
Total runtime (ms): 5063


--Key Concepts Demonstrated
- Multi-threading in C++
- Producer–Consumer architecture
- Synchronization using mutex & condition_variable
- Real-time system simulation
- Backend performance measurement
- Modular system design

--Performance
Processes ~2000 simulated patient records
Achieves ~390–400 records/sec throughput
Designed for real-time streaming simulation

--Future Improvements
REST API integration for live data streaming
Web dashboard visualization
Database integration (SQLite/PostgreSQL)
Advanced ML-based anomaly detection
Unit testing framework (Google Test)

C++ Systems Project | Backend Simulation
Built for learning real-time systems and concurrency concepts.

