#include "Mehul_Oct8_Task2_DiagnosticReport.h"
#include <iostream>
#include <algorithm>
void DiagnosticReport::addReading(const SensorReading& reading) { readings_m.push_back(reading); }
void DiagnosticReport::displayAllReadings() const {
    std::cout << "--- Full Diagnostic Report ---" << std::endl;
    for (const auto& reading : readings_m) { reading.display(); }
    std::cout << "-----------------------------" << std::endl;
}
std::vector<SensorReading> DiagnosticReport::filterBySeverity(SeverityLevel level) const {
    std::vector<SensorReading> filtered;
    for (const auto& r : readings_m) { if (r.getSeverity() == level) filtered.push_back(r); }
    return filtered;
}
void DiagnosticReport::sortBySeverityDescending() {
    std::sort(readings_m.begin(), readings_m.end(), [](const SensorReading& a, const SensorReading& b) {
        return static_cast<int>(a.getSeverity()) > static_cast<int>(b.getSeverity());
    });
}
std::map<SeverityLevel, int> DiagnosticReport::getSeverityDistribution() const {
    std::map<SeverityLevel, int> dist;
    for (const auto& r : readings_m) { dist[r.getSeverity()]++; }
    return dist;
}
const SensorReading* DiagnosticReport::findReadingByName(const std::string& name) const {
    for (const auto& r : readings_m) { if (r.getName() == name) return &r; }
    return nullptr;
}
