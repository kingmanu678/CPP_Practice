#include <iostream>
#include "Mehul_Oct8_Task3_Student.h"
int main() {
    Student student;
    student.addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    student.addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    student.addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));
    student.addScore(SubjectScore("History", 45, GradeLevel::Fail));
    student.addScore(SubjectScore("English", 88, GradeLevel::Distinction));
    student.displayAllScores();
    std::cout << "Average score: " << student.computeAverageScore() << std::endl;
    std::cout << "Number of Distinction grades: " << student.countDistinctions() << std::endl;
    student.printTopScores();
    return 0;
}
