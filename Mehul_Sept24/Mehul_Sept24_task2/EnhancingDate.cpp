#include <iostream>
#include "EnhancingDate.h"

// Constructor
Date::Date(int m, int d, int y)
{
    // Validate month
    if (m >= 1 && m <= 12)
    {
        month = m; // Valid month
    }
    else
    {
        throw std::invalid_argument("Invalid Month Value! Month (1-12)"); // Error
    }

    // Validate day
    if (d >= 1 && d <= daysInMonth(m, y))
    {
        day = d; // Valid day
    }
    else
    {
        throw std::invalid_argument("Invalid Day for the given Month and Year"); // Error
    }

    // Validate year
    if (y >= 1000 && y <= 9999)
    {
        year = y; // Valid year
    }
    else
    {
        throw std::invalid_argument("Invalid Year! Year must be between (1000-9999)"); // Error
    }
}

// Check for leap year
bool Date::isLeapYear(int yr)
{
    if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
    {
        return true; // Is a leap year
    }
    return false; // Not a leap year
}

// Get days in a month
int Date::daysInMonth(int m, int yr)
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

// Print date
void Date::print()
{
    std::cout << month << '/' << day << '/' << year;
}

// Increment to next day
void Date::nextDay()
{
    int maxDays = daysInMonth(month, year); // Get max days
    if (day < maxDays)                      // Not end of month
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