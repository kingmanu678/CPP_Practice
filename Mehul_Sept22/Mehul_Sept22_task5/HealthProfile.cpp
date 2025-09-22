#include <iostream>
#include "HealthProfile.h"

HealthProfile::HealthProfile(std::string firstName, std::string lastName, std::string gender, int birthMonth, int birthDay, int birthYear, int height, int weight) {
    setFirstName(firstName);
    setLastName(lastName);
    setGender(gender);
    setBirthDate(birthMonth, birthDay, birthYear);
    setHeight(height);
    setWeight(weight);
}

void HealthProfile::setFirstName(std::string name) {
    firstName = name;
}

std::string HealthProfile::getFirstName() const {
    return firstName;
}

void HealthProfile::setLastName(std::string name) {
    lastName = name;
}

std::string HealthProfile::getLastName() const {
    return lastName;
}

void HealthProfile::setGender(std::string g) {
    gender = g;
}

std::string HealthProfile::getGender() const {
    return gender;
}

void HealthProfile::setBirthDate(int month, int day, int year) {
    birthMonth = month;
    birthDay = day;
    birthYear = year;
}

int HealthProfile::getBirthMonth() const {
    return birthMonth;
}

int HealthProfile::getBirthDay() const {
    return birthDay;
}

int HealthProfile::getBirthYear() const {
    return birthYear;
}

void HealthProfile::setHeight(int h) {
    heightInInches = h;
}

int HealthProfile::getHeight() const {
    return heightInInches;
}

void HealthProfile::setWeight(int w) {
    weightInPounds = w;
}

int HealthProfile::getWeight() const {
    return weightInPounds;
}

int HealthProfile::getAge(int currentMonth, int currentDay, int currentYear) const {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

int HealthProfile::getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const {
    return 220 - getAge(currentMonth, currentDay, currentYear);
}

void HealthProfile::getTargetHeartRate(int currentMonth, int currentDay, int currentYear, int &minTarget, int &maxTarget) const {
    int maxRate = getMaximumHeartRate(currentMonth, currentDay, currentYear);
    minTarget = static_cast<int>(maxRate * 0.50);
    maxTarget = static_cast<int>(maxRate * 0.85);
}

double HealthProfile::getBMI() const {
    return (getWeight() * 703.0) / (getHeight() * getHeight());
}

void HealthProfile::displayBMIChart() const {
    std::cout << "\nBMI VALUES" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal:      between 18.5 and 24.9" << std::endl;
    std::cout << "Overweight:  between 25 and 29.9" << std::endl;
    std::cout << "Obese:       30 or greater" << std::endl;
}