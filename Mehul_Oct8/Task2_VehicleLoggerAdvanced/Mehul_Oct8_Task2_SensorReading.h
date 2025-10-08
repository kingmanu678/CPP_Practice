#ifndef SENSOR_READING_H
#define SENSOR_READING_H
#include <string>
#include "Mehul_Oct8_Task2_SeverityLevel.h"
class SensorReading {
private:
    std::string sensorName_m;
    double value_m;
    SeverityLevel severity_m;
public:
    SensorReading(const std::string& name, double value, SeverityLevel severity);
    void display() const;
    SeverityLevel getSeverity() const;
    std::string getName() const;
};
#endif // SENSOR_READING_H
