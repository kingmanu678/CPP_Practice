#include "Mehul_Oct8_Task3_SubjectScore.h"
#include <iostream>
std::string gradeToString(GradeLevel grade) {
    switch (grade) {
        case GradeLevel::Fail: return "Fail";
        case GradeLevel::Pass: return "Pass";
        case GradeLevel::Merit: return "Merit";
        case GradeLevel::Distinction: return "Distinction";
        default: return "Unknown";
    }
}
SubjectScore::SubjectScore(const std::string& n, int s, GradeLevel g) : subjectName_m(n), score_m(s), grade_m(g) {}
void SubjectScore::display() const {
    std::cout << "  Subject: " << subjectName_m << ", Score: " << score_m << ", Grade: " << gradeToString(grade_m) << std::endl;
}
GradeLevel SubjectScore::getGrade() const { return grade_m; }
int SubjectScore::getScore() const { return score_m; }
