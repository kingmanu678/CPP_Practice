#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Term1
    double term1 = 1.0 / (3.0 * sqrt(2.0) - 2.0 * sqrt(3.0));
    // Term2
    double term2 = 3.0 / (2.0 * sqrt(3.0) - sqrt(6.0));
    // Term3
    double term3 = 4.0 / (sqrt(6.0) - 3.0 * sqrt(2.0));

    // Combine
    double result = term1 - term2 - term3;

    // Verify
    double analytical_result = (9.0 * sqrt(2.0) - 4.0 * sqrt(3.0) - sqrt(6.0)) / 6.0;

    // Output
    std::cout << "Calculating the expression numerically:" << std::endl;
    std::cout << "1 / (3*sqrt(2) - 2*sqrt(3)) = " << term1 << std::endl;
    std::cout << "3 / (2*sqrt(3) - sqrt(6))   = " << term2 << std::endl;
    std::cout << "4 / (sqrt(6) - 3*sqrt(2))   = " << term3 << std::endl;
    
    std::cout << std::fixed << std::setprecision(10);

    std::cout << "\nFinal Numerical Result: " << result << std::endl;
    std::cout << "Analytical Result:      " << analytical_result << std::endl;
    
    return 0;
}