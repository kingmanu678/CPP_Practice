#include <iostream>
#include "EnhancingClass.h"

int main()
{
    // Test case 1: Minute boundary
    std::cout << "Incrementing into next minute:\n";
    Time t1(4, 55, 58); // Near minute end

    for (int i = 0; i < 5; ++i)
    {
        t1.printStandard(); // Show time
        t1.tick();          // Increment time
    }

    // Test case 2: Hour boundary
    std::cout << "\nIncrementing into next hour:\n";
    Time t2(1, 59, 58); // Near hour end

    for (int i = 0; i < 5; ++i)
    {
        t2.printStandard(); // Show time
        t2.tick();          // Increment time
    }

    // Test case 3: Day boundary
    std::cout << "\nIncrementing into next day:\n";
    Time t3(23, 59, 58); // Near day end
    
    for (int i = 0; i < 5; ++i)
    {
        t3.printStandard(); // Show time
        t3.tick();          // Increment time
    }

    return 0; // Success
}
