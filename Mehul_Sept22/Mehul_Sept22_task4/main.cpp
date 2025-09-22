#include <iostream>
#include "HeartRates.h"

int main() {
    HeartRates person("John", "Doe", 9, 22, 1990);
    int minTarget, maxTarget;

    std::cout << "First Name: " << person.getFirstName() << std::endl;
    std::cout << "Last Name: " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;
    std::cout << "Age: " << person.getAge(9, 22, 2025) << " years" << std::endl;
    std::cout << "Maximum Heart Rate: " << person.getMaximumHeartRate(9, 22, 2025) << " bpm" << std::endl;

    person.getTargetHeartRate(9, 22, 2025, minTarget, maxTarget);
    std::cout << "Target Heart Rate Range: " << minTarget << " - " << maxTarget << " bpm" << std::endl;

    return 0;
}