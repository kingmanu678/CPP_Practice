#ifndef DATEANDTIME_H
#define DATEANDTIME_H

// DateAndTime class definition
class DateAndTime
{
private:
    // Date members
    int day;
    int month;
    int year;

    // Time members
    int hour;
    int minute;
    int second;

    // Private helper functions
    bool isLeapYear(int yr);            // Check for leap year
    int daysInMonth(int month, int yr); // Get days in month

public:
    // Constructor
    DateAndTime(int month_, int year_, int day_, int hour_, int minute_, int second_);

    // Public methods
    void tick();           // Increment second
    void nextDay();        // Increment day
    void printUniversal(); // Print universal format
    void printStandard();  // Print standard format
};

#endif