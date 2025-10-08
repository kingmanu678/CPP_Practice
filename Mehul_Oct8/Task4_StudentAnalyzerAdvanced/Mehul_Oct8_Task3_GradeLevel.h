#ifndef GRADE_LEVEL_H
#define GRADE_LEVEL_H
#include <string>
enum class GradeLevel { Fail, Pass, Merit, Distinction };
std::string gradeToString(GradeLevel grade);
#endif // GRADE_LEVEL_H
