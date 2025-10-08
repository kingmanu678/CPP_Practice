#include "Mehul_Oct8_Task1_DiagnosticReport.h"
#include <iostream>
void DiagnosticReport::addReading(const SensorReading& reading) { readings_m.push_back(reading); }
void DiagnosticReport::displayAllReadings() const {
    std::cout << "--- Full Diagnostic Report ---" << std::endl;
    for (const auto& reading : readings_m) { reading.display(); }
    std::cout << "-----------------------------" << std::endl;
}
int DiagnosticReport::countReadingsAtOrAbove(SeverityLevel level) const {
    int count = 0;
    for (const auto& reading : readings_m) {
        if (static_cast<int>(reading.getSeverity()) >= static_cast<int>(level)) { count++; }
    }
    return count;
}
