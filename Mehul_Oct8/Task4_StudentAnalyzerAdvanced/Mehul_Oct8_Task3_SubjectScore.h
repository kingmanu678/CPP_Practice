#ifndef SUBJECT_SCORE_H
#define SUBJECT_SCORE_H
#include <string>
#include "Mehul_Oct8_Task3_GradeLevel.h"
class SubjectScore {
private:
    std::string subjectName_m;
    int score_m;
    GradeLevel grade_m;
public:
    SubjectScore(const std::string& name = "", int score = 0, GradeLevel grade = GradeLevel::Fail);
    void display() const;
    GradeLevel getGrade() const;
    int getScore() const;
};
#endif // SUBJECT_SCORE_H
