#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "DateAndTime.h"

// Constructor
DateAndTime::DateAndTime(int month_, int year_, int day_, int hour_, int minute_, int second_)
{
    // Validate and set date and time
    if (month_ < 1 || month_ > 12)
    {
        throw std::invalid_argument("Invalid month"); // Error
    }
    else
    {
        month = month_; // Set month
    }
    if (year_ < 1000 || year_ > 9999)
    {
        throw std::invalid_argument("Invalid year"); // Error
    }
    else
    {
        year = year_; // Set year
    }
    if (day_ < 1 || day_ > daysInMonth(month, year))
    {
        throw std::invalid_argument("Invalid day"); // Error
    }
    else
    {
        day = day_; // Set day
    }

    if (hour_ < 0 || hour_ > 23)
    {
        throw std::invalid_argument("Invalid hour"); // Error
    }
    else
    {
        hour = hour_; // Set hour
    }
    if (minute_ < 0 || minute_ > 59)
    {
        throw std::invalid_argument("Invalid minute"); // Error
    }
    else
    {
        minute = minute_; // Set minute
    }
    if (second_ < 0 || second_ > 59)
    {
        throw std::invalid_argument("Invalid second"); // Error
    }
    else
    {
        second = second_; // Set second
    }
}

// Check for leap year
bool DateAndTime::isLeapYear(int yr)
{
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
    {
        return true; // Is a leap year
    }
    return false; // Not a leap year
}

// Get days in a month
int DateAndTime::daysInMonth(int m, int yr)
{
    // February
    if (m == 2)
    {
        return isLeapYear(yr) ? 29 : 28; // Leap or not
    }

    // Other months
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30; // 30 days
    }
    else
    {
        return 31; // 31 days
    }
}

// Increment second
void DateAndTime::tick()
{
    second++; // Increment second
    if (second == 60) // New minute
    {
        second = 0;
        minute++; // Increment minute
        if (minute == 60) // New hour
        {
            minute = 0;
            hour++; // Increment hour
            if (hour == 24) // New day
            {
                hour = 0;
                nextDay(); // Go to next day
            }
        }
    }
}

// Increment day
void DateAndTime::nextDay()
{
    int maxDay = daysInMonth(month, year); // Get max days
    if (day < maxDay)                      // Not end of month
    {
        day++; // Increment day
    }
    else // End of month
    {
        day = 1;        // Reset day
        if (month < 12) // Not end of year
        {
            month++; // Increment month
        }
        else // End of year
        {
            month = 1; // Reset month
            year++;    // Increment year
        }
    }
}

// Print universal format
void DateAndTime::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << month << "/"
              << std::setw(2) << day << "/" << year << " "
              << std::setw(2) << hour << ":" << std::setw(2) << minute << ":"
              << std::setw(2) << second << std::endl;
}

// Print standard format
void DateAndTime::printStandard()
{
    std::cout << std::setfill('0') << std::setw(2) << month << "/"
              << std::setw(2) << day << "/" << year << " "
              << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setw(2) << minute << ":" << std::setw(2) << second
              << (hour < 12 ? " AM" : " PM") << std::endl;
}