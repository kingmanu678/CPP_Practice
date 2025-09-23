#include <iostream>
#include <array>
#include <string>
#include <iomanip>

void printBoardingPass(int seat);
int assignSeat(std::array<bool, 10>& seats, int start, int end);
bool isSectionFull(const std::array<bool, 10>& seats, int start, int end);
bool isPlaneFull(const std::array<bool, 10>& seats);

int main() {
    std::array<bool, 10> seats{}; // SeatingChart
    
    // BookingLoop
    while (!isPlaneFull(seats)) {
        std::cout << "\nPlease type 1 for \"First Class\"\n";
        std::cout << "Please type 2 for \"Economy\"\n";
        std::cout << "Choice: ";
        char choice;
        std::cin >> choice;

        int seatNumber = -1;

        // FirstClass
        if (choice == '1') {
            if (!isSectionFull(seats, 0, 5)) {
                seatNumber = assignSeat(seats, 0, 5);
                printBoardingPass(seatNumber);
            } else {
                std::cout << "First Class is full. Is it acceptable to be placed in the Economy section? (y/n): ";
                char response;
                std::cin >> response;
                if ((response == 'y' || response == 'Y') && !isSectionFull(seats, 5, 10)) {
                    seatNumber = assignSeat(seats, 5, 10);
                    printBoardingPass(seatNumber);
                } else {
                    std::cout << "Next flight leaves in 3 hours." << std::endl;
                }
            }
        // Economy
        } else if (choice == '2') {
            if (!isSectionFull(seats, 5, 10)) {
                seatNumber = assignSeat(seats, 5, 10);
                printBoardingPass(seatNumber);
            } else {
                std::cout << "Economy section is full. Is it acceptable to be placed in the First Class section? (y/n): ";
                char response;
                std::cin >> response;
                if ((response == 'y' || response == 'Y') && !isSectionFull(seats, 0, 5)) {
                    seatNumber = assignSeat(seats, 0, 5);
                    printBoardingPass(seatNumber);
                } else {
                    std::cout << "Next flight leaves in 3 hours." << std::endl;
                }
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout << "\nThe plane is now full." << std::endl;

    return 0;
}

// BoardingPass
void printBoardingPass(int seat) {
    std::cout << "\n-------------------------\n";
    std::cout << "  BOARDING PASS\n";
    std::cout << "-------------------------\n";
    std::cout << "SEAT: " << std::setw(3) << seat << "\n";
    std::cout << "SECTION: " << (seat <= 5 ? "First Class" : "Economy") << "\n";
    std::cout << "-------------------------\n\n";
}

// Assign
int assignSeat(std::array<bool, 10>& seats, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (!seats[i]) {
            seats[i] = true;
            return i + 1;
        }
    }
    return -1;
}

// CheckSection
bool isSectionFull(const std::array<bool, 10>& seats, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (!seats[i]) {
            return false;
        }
    }
    return true;
}

// CheckPlane
bool isPlaneFull(const std::array<bool, 10>& seats) {
    for (bool seat : seats) {
        if (!seat) {
            return false;
        }
    }
    return true;
}
