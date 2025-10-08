#ifndef SEVERITY_LEVEL_H
#define SEVERITY_LEVEL_H
#include <string>
enum class SeverityLevel { Low, Medium, High, Critical };
std::string severityToString(SeverityLevel level);
#endif // SEVERITY_LEVEL_H
