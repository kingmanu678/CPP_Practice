#include "Mehul_Oct8_Task3_Student.h"
#include <iostream>
Student::Student(int maxSubjects) : currentSize_m(0), maxSize_m(maxSubjects) { scores_m = new SubjectScore[maxSize_m]; }
Student::~Student() { delete[] scores_m; }
void Student::addScore(const SubjectScore& score) { if (currentSize_m < maxSize_m) scores_m[currentSize_m++] = score; }
double Student::computeAverageScore() const {
    if (currentSize_m == 0) return 0.0;
    double total = 0;
    for (int i=0; i < currentSize_m; ++i) total += scores_m[i].getScore();
    return total / currentSize_m;
}
int Student::countDistinctions() const {
    int count = 0;
    for (int i=0; i < currentSize_m; ++i) if (scores_m[i].getGrade() == GradeLevel::Distinction) count++;
    return count;
}
void Student::printTopScores() const {
    std::cout << "\nTop Scores (Merit and Distinction):" << std::endl;
    for (int i=0; i < currentSize_m; ++i) {
        GradeLevel g = scores_m[i].getGrade();
        if (g == GradeLevel::Merit || g == GradeLevel::Distinction) scores_m[i].display();
    }
}
void Student::displayAllScores() const {
    std::cout << "--- All Student Scores ---" << std::endl;
    for (int i=0; i < currentSize_m; ++i) scores_m[i].display();
    std::cout << "--------------------------" << std::endl;
}
