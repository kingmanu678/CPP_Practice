#include "Mehul_Oct8_Task4_Student.h"
Student::Student(const std::string& n, int maxS) : studentName_m(n), currentSize_m(0), maxSize_m(maxS) { scores_m = new SubjectScore[maxS]; }
Student::~Student() { delete[] scores_m; }
void Student::addScore(const SubjectScore& s) { if (currentSize_m < maxSize_m) scores_m[currentSize_m++] = s; }
std::string Student::getName() const { return studentName_m; }
const SubjectScore* Student::getScores() const { return scores_m; }
int Student::getScoreCount() const { return currentSize_m; }
