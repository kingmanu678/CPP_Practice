#include <iostream>
#include "DateAndTime.h"

int main()
{
    // Test case: Next day
    std::cout << "Testing tick into next day:\n";
    DateAndTime date(12, 31, 2025, 23, 59, 58); // Near end of day

    // Loop to show time increment
    for (int i = 0; i < 5; ++i)
    {
        date.printStandard(); // Print date and time
        date.tick();          // Increment time
    }

    return 0; // Success
}