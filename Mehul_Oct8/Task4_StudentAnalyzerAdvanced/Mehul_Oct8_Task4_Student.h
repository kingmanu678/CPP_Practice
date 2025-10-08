#ifndef STUDENT_H
#define STUDENT_H
#include "Mehul_Oct8_Task3_SubjectScore.h"
#include <string>
class Student {
private:
    std::string studentName_m;
    SubjectScore* scores_m;
    int currentSize_m;
    int maxSize_m;
public:
    Student(const std::string& name, int maxSubjects = 10);
    ~Student();
    void addScore(const SubjectScore& score);
    std::string getName() const;
    const SubjectScore* getScores() const;
    int getScoreCount() const;
};
#endif // STUDENT_H
