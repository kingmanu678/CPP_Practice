#ifndef DIAGNOSTIC_REPORT_H
#define DIAGNOSTIC_REPORT_H
#include "Mehul_Oct8_Task1_SensorReading.h"
#include <vector>
class DiagnosticReport {
private:
    std::vector<SensorReading> readings_m;
public:
    void addReading(const SensorReading& reading);
    void displayAllReadings() const;
    int countReadingsAtOrAbove(SeverityLevel level) const;
};
#endif // DIAGNOSTIC_REPORT_H
