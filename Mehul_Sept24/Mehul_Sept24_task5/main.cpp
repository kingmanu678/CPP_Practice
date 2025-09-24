#include <iostream>
#include <ctime>
#include <cstdlib>
#include "TicTacToe.h"
#include "globalFunctionalities.h"

int main()
{
    std::srand(std::time(0)); // Seed random

    int choice; // User's menu choice

    do
    {
        // Display menu
        std::cout << "\n===== TicTacToe Menu =====\n";
        std::cout << "1. Start New Game (Human vs Computer)\n";
        std::cout << "2. Start New Game (Human vs Human)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice; // Get choice

        switch (choice)
        {
        case 1:
            playGameHumanVsComputer(); // Human vs Computer
            break;
        case 2:
            playGameHumanVsHuman(); // Human vs Human
            break;
        case 3:
            std::cout << "Thanks for playing!\n"; // Exit
            break;
        default:
            std::cout << "Invalid choice. Try again.\n"; // Invalid
        }
    } while (choice != 3); // Loop until exit

    return 0; // Success
}