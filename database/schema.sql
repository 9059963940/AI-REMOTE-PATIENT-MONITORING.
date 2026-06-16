CREATE TABLE patients (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    patient_id INTEGER,
    heart_rate INTEGER,
    spo2 INTEGER,
    temperature REAL,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);