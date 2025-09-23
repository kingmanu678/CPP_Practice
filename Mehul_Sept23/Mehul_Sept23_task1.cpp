#include <iostream>
#include <array>

int main() {
    std::array<int, 20> unique_numbers{}; // Storage
    int unique_count = 0; // Counter
    const int total_numbers = 20;
    const int min_val = 10;
    const int max_val = 100;

    std::cout << "Enter " << total_numbers << " numbers between " << min_val << " and " << max_val << ", inclusive." << std::endl;

    // Input
    for (int i = 0; i < total_numbers; ++i) {
        int num;
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> num;

        // Validate
        if (num >= min_val && num <= max_val) {
            bool is_duplicate = false;
            // Check
            for (int j = 0; j < unique_count; ++j) {
                if (unique_numbers[j] == num) {
                    is_duplicate = true;
                    break;
                }
            }
            // Add
            if (!is_duplicate) {
                if (unique_count < total_numbers) {
                    unique_numbers[unique_count] = num;
                    unique_count++;
                }
            }
        } else {
            std::cout << "Invalid number. Please enter a number between " << min_val << " and " << max_val << "." << std::endl;
        }
    }

    // Output
    std::cout << "\nUnique values entered:" << std::endl;
    for (int i = 0; i < unique_count; ++i) {
        std::cout << unique_numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
