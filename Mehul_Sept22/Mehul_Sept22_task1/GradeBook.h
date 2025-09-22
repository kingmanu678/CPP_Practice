#include <string>

class GradeBook {
public:
    GradeBook(std::string courseName, std::string instructorName);
    void setCourseName(std::string name);
    std::string getCourseName() const;
    void setInstructorName(std::string name);
    std::string getInstructorName() const;
    void displayMessage() const;

private:
    std::string courseName;
    std::string instructorName;
};