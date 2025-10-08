#include "Mehul_Oct8_Task4_GlobalFunctions.h"
#include <iostream>
#include <map>
void summarizeGrades(const Student* students[], int studentCount) {
    std::map<GradeLevel, int> counts;
    for (int i=0; i < studentCount; ++i) {
        if (students[i]) {
            for (int j=0; j < students[i]->getScoreCount(); ++j) counts[students[i]->getScores()[j].getGrade()]++;
        }
    }
    std::cout << "\n--- Global Grade Summary ---\n"
              << "Fail: " << counts[GradeLevel::Fail] << "\n"
              << "Pass: " << counts[GradeLevel::Pass] << "\n"
              << "Merit: " << counts[GradeLevel::Merit] << "\n"
              << "Distinction: " << counts[GradeLevel::Distinction] << "\n"
              << "--------------------------" << std::endl;
}
const SubjectScore* findTopScorer(const Student* students[], int studentCount, const std::string& subject) {
    const SubjectScore* topScorer = nullptr;
    int highestScore = -1;
    for (int i=0; i < studentCount; ++i) {
        if (students[i]) {
            for (int j=0; j < students[i]->getScoreCount(); ++j) {
                if (students[i]->getScores()[j].getSubjectName() == subject) {
                    if (students[i]->getScores()[j].getScore() > highestScore) {
                        highestScore = students[i]->getScores()[j].getScore();
                        topScorer = &students[i]->getScores()[j];
                    }
                }
            }
        }
    }
    return topScorer;
}
void exportAllDistinctions(const Student* students[], int studentCount) {
    std::cout << "\n--- Printing All Distinction Scores ---" << std::endl;
    for (int i=0; i < studentCount; ++i) {
        if (students[i]) {
            for (int j=0; j<students[i]->getScoreCount(); ++j) {
                if (students[i]->getScores()[j].getGrade() == GradeLevel::Distinction) {
                    std::cout << "Student: " << students[i]->getName() << ", ";
                    students[i]->getScores()[j].display();
                }
            }
        }
    }
    std::cout << "-----------------------------------" << std::endl;
}
