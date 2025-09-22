#include "HeartRates.h"

HeartRates::HeartRates(std::string firstName, std::string lastName, int birthMonth, int birthDay, int birthYear) {
    setFirstName(firstName);
    setLastName(lastName);
    setBirthDate(birthMonth, birthDay, birthYear);
}

void HeartRates::setFirstName(std::string name) {
    firstName = name;
}

std::string HeartRates::getFirstName() const {
    return firstName;
}

void HeartRates::setLastName(std::string name) {
    lastName = name;
}

std::string HeartRates::getLastName() const {
    return lastName;
}

void HeartRates::setBirthDate(int month, int day, int year) {
    birthMonth = month;
    birthDay = day;
    birthYear = year;
}

int HeartRates::getBirthMonth() const {
    return birthMonth;
}

int HeartRates::getBirthDay() const {
    return birthDay;
}

int HeartRates::getBirthYear() const {
    return birthYear;
}

int HeartRates::getAge(int currentMonth, int currentDay, int currentYear) const {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

int HeartRates::getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const {
    return 220 - getAge(currentMonth, currentDay, currentYear);
}

void HeartRates::getTargetHeartRate(int currentMonth, int currentDay, int currentYear, int &minTarget, int &maxTarget) const {
    int maxRate = getMaximumHeartRate(currentMonth, currentDay, currentYear);
    minTarget = static_cast<int>(maxRate * 0.50);
    maxTarget = static_cast<int>(maxRate * 0.85);
}