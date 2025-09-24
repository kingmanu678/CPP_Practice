#ifndef ENHANCING_DATE_H
#define ENHANCING_DATE_H

// Date class definition
class Date
{
private:
    int month; // Month
    int day;   // Day
    int year;  // Year

public:
    // Default constructor
    Date(int = 1, int = 1, int = 2000);

    // Public methods
    void print();   // Print date
    void nextDay(); // Increment day

    // Helper functions
    bool isLeapYear(int yr);            // Check for leap year
    int daysInMonth(int month, int yr); // Get days in month

}; // end class Date
#endif