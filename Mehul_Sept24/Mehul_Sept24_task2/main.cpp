#include <iostream>
#include "EnhancingDate.h"

int main()
{
    // Test case 1: Next month
    std::cout << "\nIncrement to the next month \n";
    Date date1 = Date(3, 31, 2025); // March 31, 2025
    date1.nextDay();                // Increment day
    date1.print();                  // Print new date

    // Test case 2: Next year
    std::cout << "\nIncrement to the next year \n";
    Date date2 = Date(12, 31, 2025); // Dec 31, 2025
    date2.nextDay();                 // Increment day
    date2.print();                   // Print new date

    return 0; // Success
}