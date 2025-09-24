#include <iostream>
#include <iomanip>
#include "EnhancingClass.h"

// Constructor
Time::Time(int hr, int min, int sc)
{
    setTime(hr, min, sc); // Use setter to initialize
}

// Set H, M, S
void Time::setTime(int h, int m, int s)
{
    setHour(h);   // Set hour
    setMinute(m); // Set minute
    setSecond(s); // Set second
}

// Set hour
void Time::setHour(int h)
{
    // Validate hour
    if (h >= 0 && h < 24)
    {
        hour = h;
    }
    else
    {
        hour = 0; // Default to 0
    }
}

// Set minute
void Time::setMinute(int m)
{
    // Validate minute
    if (m >= 0 && m < 60)
    {
        minute = m;
    }
    else
    {
        minute = 0; // Default to 0
    }
}

// Set second
void Time::setSecond(int s)
{
    // Validate second
    if (s >= 0 && s < 60)
    {
        second = s;
    }
    else
    {
        second = 0; // Default to 0
    }
}

// Get hour
int Time::getHour()
{
    return hour;
}

// Get minute
int Time::getMinute()
{
    return minute;
}

// Get second
int Time::getSecond()
{
    return second;
}

// Print universal time
void Time::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":" << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << std::endl;
}

// Print standard time
void Time::printStandard()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : (getHour() % 12)) << ":" << std::setfill('0') << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << std::endl;
}

// Increment second
void Time::tick()
{
    int sec = (getSecond() + 1); // New second
    if (sec == 60) // New minute
    {
        sec = 0;
        int min = (getMinute() + 1); // New minute

        if (min == 60) // New hour
        {
            min = 0;
            int hr = (getHour() + 1); // New hour
            if (hr == 24) // New day
            {
                hr = 0;
            }
            setHour(hr);
        }
        setMinute(min);
    }
    setSecond(sec);
}