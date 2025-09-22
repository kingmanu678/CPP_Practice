#include <string>

class HealthProfile {
public:
    HealthProfile(std::string firstName, std::string lastName, std::string gender, int birthMonth, int birthDay, int birthYear, int height, int weight);
    void setFirstName(std::string name);
    std::string getFirstName() const;
    void setLastName(std::string name);
    std::string getLastName() const;
    void setGender(std::string gender);
    std::string getGender() const;
    void setBirthDate(int month, int day, int year);
    int getBirthMonth() const;
    int getBirthDay() const;
    int getBirthYear() const;
    void setHeight(int height);
    int getHeight() const;
    void setWeight(int weight);
    int getWeight() const;
    int getAge(int currentMonth, int currentDay, int currentYear) const;
    int getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const;
    void getTargetHeartRate(int currentMonth, int currentDay, int currentYear, int &minTarget, int &maxTarget) const;
    double getBMI() const;
    void displayBMIChart() const;

private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthMonth;
    int birthDay;
    int birthYear;
    int heightInInches;
    int weightInPounds;
};