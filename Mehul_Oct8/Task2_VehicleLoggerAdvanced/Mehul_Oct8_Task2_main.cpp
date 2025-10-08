#include <iostream>
#include "Mehul_Oct8_Task2_DiagnosticReport.h"
int main() {
    DiagnosticReport report;
    report.addReading(SensorReading("EngineTemp", 105.0, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20.0, SeverityLevel::Medium));
    report.addReading(SensorReading("Brake Fluid Level", 5.0, SeverityLevel::Critical));
    report.addReading(SensorReading("Battery Voltage", 12.5, SeverityLevel::Low));
    std::cout << "Severity Distribution Map:" << std::endl;
    auto dist = report.getSeverityDistribution();
    for(const auto& p : dist) { std::cout << "  " << severityToString(p.first) << ": " << p.second << std::endl; }
    std::cout << "\nReport Sorted by Severity (Descending):" << std::endl;
    report.sortBySeverityDescending();
    report.displayAllReadings();
    std::cout << "\nFiltered - Critical Readings Only:" << std::endl;
    auto criticals = report.filterBySeverity(SeverityLevel::Critical);
    for(const auto& r : criticals) { r.display(); }
    std::cout << "\nSearching for 'Brake Fluid Level'..." << std::endl;
    const SensorReading* found = report.findReadingByName("Brake Fluid Level");
    if (found) { std::cout << "Found Reading:" << std::endl; found->display(); }
    return 0;
}
