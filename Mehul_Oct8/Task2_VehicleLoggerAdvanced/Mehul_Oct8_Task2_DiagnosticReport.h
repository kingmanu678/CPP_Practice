#ifndef DIAGNOSTIC_REPORT_H
#define DIAGNOSTIC_REPORT_H
#include "Mehul_Oct8_Task2_SensorReading.h"
#include <vector>
#include <map>
class DiagnosticReport {
private:
    std::vector<SensorReading> readings_m;
public:
    void addReading(const SensorReading& reading);
    void displayAllReadings() const;
    std::vector<SensorReading> filterBySeverity(SeverityLevel level) const;
    void sortBySeverityDescending();
    std::map<SeverityLevel, int> getSeverityDistribution() const;
    const SensorReading* findReadingByName(const std::string& name) const;
};
#endif // DIAGNOSTIC_REPORT_H
