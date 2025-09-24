#include <iostream>

#include "ErrorIndicators.h"

int main()
{
    Time test_time; // Time object for testing
    std::cout << "Testing valid time:\n";

    // Test setTime with valid input
    if (!test_time.setTime(13, 45, 30))
    {
        throw std::invalid_argument("Error: Invalid time input\n"); // Should not happen
    }
    test_time.printUniversal(); // Print universal
    test_time.printStandard();  // Print standard

    // Test setHour with invalid input
    std::cout << "\nTesting invalid hour:\n";
    if (!test_time.setHour(25)) // Invalid hour
    {
        throw std::invalid_argument("Error: Invalid Hour\n"); // Should happen
    }

    // Test setMinute with invalid input
    std::cout << "\nTesting invalid minute:\n";
    if (!test_time.setMinute(75)) // Invalid minute
    {
        throw std::invalid_argument("Error: Invalid Minute\n"); // Should happen
    }

    // Test setSecond with invalid input
    std::cout << "\nTesting invalid second:\n";
    if (!test_time.setSecond(-5)) // Invalid second
    {
        throw std::invalid_argument("Error: Invalid Second\n"); // Should happen
    }

    // Final state of test_time
    std::cout << "\nFinal time state:\n";
    test_time.printUniversal();
    test_time.printStandard();

    // Test tick function
    std::cout << "Incrementing into next minute:\n";
    Time t1(4, 55, 58); // Near minute end
    for (int i = 0; i < 5; ++i)
    {
        t1.printStandard(); // Show time
        t1.tick();          // Increment time
    }

    return 0; // Success
}