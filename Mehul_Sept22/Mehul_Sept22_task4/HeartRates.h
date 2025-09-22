#include <string>

class HeartRates {
public:
    HeartRates(std::string firstName, std::string lastName, int birthMonth, int birthDay, int birthYear);
    void setFirstName(std::string name);
    std::string getFirstName() const;
    void setLastName(std::string name);
    std::string getLastName() const;
    void setBirthDate(int month, int day, int year);
    int getBirthMonth() const;
    int getBirthDay() const;
    int getBirthYear() const;
    int getAge(int currentMonth, int currentDay, int currentYear) const;
    int getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const;
    void getTargetHeartRate(int currentMonth, int currentDay, int currentYear, int &minTarget, int &maxTarget) const;

private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
};