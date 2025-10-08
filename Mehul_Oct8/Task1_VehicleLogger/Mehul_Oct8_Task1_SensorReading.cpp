#include "Mehul_Oct8_Task1_SensorReading.h"
#include <iostream>
std::string severityToString(SeverityLevel level) {
    switch (level) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
        default: return "Unknown";
    }
}
SensorReading::SensorReading(const std::string& name, double value, SeverityLevel severity)
    : sensorName_m(name), value_m(value), severity_m(severity) {}
void SensorReading::display() const {
    std::cout << "  Sensor: " << sensorName_m << ", Value: " << value_m << ", Severity: " << severityToString(severity_m) << std::endl;
}
SeverityLevel SensorReading::getSeverity() const { return severity_m; }
