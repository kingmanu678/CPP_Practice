#ifndef STUDENT_H
#define STUDENT_H
#include "Mehul_Oct8_Task3_SubjectScore.h"
class Student {
private:
    SubjectScore* scores_m;
    int currentSize_m;
    int maxSize_m;
public:
    Student(int maxSubjects = 10);
    ~Student();
    void addScore(const SubjectScore& score);
    double computeAverageScore() const;
    int countDistinctions() const;
    void printTopScores() const;
    void displayAllScores() const;
};
#endif // STUDENT_H
