#ifndef ERROR_INDICATORS_H
#define ERROR_INDICATORS_H

// Time class definition
class Time
{
private:
    int hour;   // Hour (0-23)
    int minute; // Minute (0-59)
    int second; // Second (0-59)

public:
    // Constructor
    Time(int = 0, int = 0, int = 0);

    // Setters with error checking
    bool setTime(int = 0, int = 0, int = 0); // Set H, M, S
    bool setHour(int);                       // Set hour
    bool setMinute(int);                     // Set minute
    bool setSecond(int);                     // Set second

    // Getters
    int getHour();   // Get hour
    int getMinute(); // Get minute
    int getSecond(); // Get second

    // Public methods
    void printUniversal(); // Print universal format
    void printStandard();  // Print standard format
    void tick();           // Increment second
};
#endif