#include <iostream>
#include "HealthProfile.h"

int main() {
    HealthProfile person("Jane", "Doe", "Female", 9, 22, 1990, 65, 140);
    int minTarget, maxTarget;

    std::cout << "First Name: " << person.getFirstName() << std::endl;
    std::cout << "Last Name: " << person.getLastName() << std::endl;
    std::cout << "Gender: " << person.getGender() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;
    std::cout << "Height: " << person.getHeight() << " inches" << std::endl;
    std::cout << "Weight: " << person.getWeight() << " pounds" << std::endl;
    std::cout << "Age: " << person.getAge(9, 22, 2025) << " years" << std::endl;
    std::cout << "BMI: " << person.getBMI() << std::endl;
    std::cout << "Maximum Heart Rate: " << person.getMaximumHeartRate(9, 22, 2025) << " bpm" << std::endl;

    person.getTargetHeartRate(9, 22, 2025, minTarget, maxTarget);
    std::cout << "Target Heart Rate Range: " << minTarget << " - " << maxTarget << " bpm" << std::endl;

    person.displayBMIChart();

    return 0;
}