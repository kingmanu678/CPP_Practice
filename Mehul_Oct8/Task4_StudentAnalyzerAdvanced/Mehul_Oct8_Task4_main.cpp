#include <iostream>
#include "Mehul_Oct8_Task4_Student.h"
#include "Mehul_Oct8_Task4_GlobalFunctions.h"
#include "Mehul_Oct8_Task3_SubjectScore.h"
#include "Mehul_Oct8_Task3_GradeLevel.h"
int main() {
    Student s1("Alice"), s2("Bob"), s3("Charlie");
    s1.addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    s1.addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    s2.addScore(SubjectScore("Math", 85, GradeLevel::Distinction));
    s2.addScore(SubjectScore("Physics", 80, GradeLevel::Merit));
    s3.addScore(SubjectScore("Math", 95, GradeLevel::Distinction));
    s3.addScore(SubjectScore("English", 88, GradeLevel::Distinction));
    const Student* students[] = {&s1, &s2, &s3};
    summarizeGrades(students, 3);
    std::cout << "\nFinding top scorer for Math..." << std::endl;
    const SubjectScore* top = findTopScorer(students, 3, "Math");
    if (top) { std::cout << "Top score in Math found:" << std::endl; top->display(); }
    exportAllDistinctions(students, 3);
    return 0;
}
