#ifndef ENHANCING_CLASS_H
#define ENHANCING_CLASS_H

// Time class definition
class Time
{
private:
    int hour;   // Hour (0-23)
    int minute; // Minute (0-59)
    int second; // Second (0-59)

public:
    // Constructor with default values
    Time(int = 0, int = 0, int = 0);

    // Setters
    void setTime(int = 0, int = 0, int = 0); // Set H, M, S
    void setHour(int);                       // Set just hour
    void setMinute(int);                     // Set just minute
    void setSecond(int);                     // Set just second

    // Getters
    int getHour();   // Get hour
    int getMinute(); // Get minute
    int getSecond(); // Get second

    // Public methods
    void printUniversal(); // Print in universal format
    void printStandard();  // Print in standard format
    void tick();           // Increment second
};
#endif