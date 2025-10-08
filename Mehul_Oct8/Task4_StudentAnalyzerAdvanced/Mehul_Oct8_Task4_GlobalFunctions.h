#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H
#include "Mehul_Oct8_Task4_Student.h"
void summarizeGrades(const Student* students[], int studentCount);
const SubjectScore* findTopScorer(const Student* students[], int studentCount, const std::string& subject);
void exportAllDistinctions(const Student* students[], int studentCount);
#endif // GLOBAL_FUNCTIONS_H
