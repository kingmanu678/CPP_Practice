#include <iostream>
#include "Mehul_Oct8_Task1_DiagnosticReport.h"
int main() {
    DiagnosticReport report;
    report.addReading(SensorReading("EngineTemp", 105.0, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20.0, SeverityLevel::Medium));
    report.addReading(SensorReading("Brake Fluid Level", 5.0, SeverityLevel::Critical));
    report.addReading(SensorReading("Battery Voltage", 12.5, SeverityLevel::Low));
    report.displayAllReadings();
    int highOrCriticalCount = report.countReadingsAtOrAbove(SeverityLevel::High);
    std::cout << "\nNumber of readings with severity High or Critical: " << highOrCriticalCount << std::endl;
    return 0;
}
