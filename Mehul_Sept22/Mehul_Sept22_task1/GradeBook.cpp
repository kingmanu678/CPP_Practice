#include <iostream>
#include "GradeBook.h"

GradeBook::GradeBook(std::string courseName, std::string instructorName) {
    setCourseName(courseName);
    setInstructorName(instructorName);
}

void GradeBook::setCourseName(std::string name) {
    courseName = name;
}

std::string GradeBook::getCourseName() const {
    return courseName;
}

void GradeBook::setInstructorName(std::string name) {
    instructorName = name;
}

std::string GradeBook::getInstructorName() const {
    return instructorName;
}

void GradeBook::displayMessage() const {
    std::cout << "Welcome to the grade book for\n" << getCourseName() << "!" << std::endl;
    std::cout << "This course is presented by: " << getInstructorName() << std::endl;
}