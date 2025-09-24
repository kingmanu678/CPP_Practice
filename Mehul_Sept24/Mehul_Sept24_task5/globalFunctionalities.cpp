#include <iostream>
#include "globalFunctionalities.h"
#include "TicTacToe.h"

// Human vs Computer game logic
void playGameHumanVsComputer()
{
    TicTacToe game1 = TicTacToe(); // Create game
    int player;                    // Current player
    std::cout << "Do you want to go first? (1 = yes, 2 = no): "; // Ask who goes first
    std::cin >> player;            // Get choice

    int row;
    int col;

    while (true) // Game loop
    {
        game1.DisplayBoard(); // Show board
        if (player == 1)      // Human's turn
        {
            std::cout << "Player " << player << " turn .\n";
            std::cout << "Select row (row(0-2): "; // Get row
            std::cin >> row;

            std::cout << "Select column (column(0-2): "; // Get column
            std::cin >> col;

            if (!game1.makeMove(player, row, col)) // Make move
            {
                std::cout << "Invalid Move! Please Try again.\n"; // Invalid move
                continue;
            }
        }
        else // Computer's turn
        {
            std::cout << "Computer Move\n";
            game1.computerMove(); // Computer makes a move
        }

        int winner = game1.whoWin(); // Check for winner
        if (winner != 0)
        {
            game1.DisplayBoard(); // Show final board

            if (player == 1)
            {
                std::cout << "Player " << winner << " wins!\n"; // Player 1 wins
            }
            else
            {
                std::cout << "Computer Wins! \n"; // Computer wins
            }
            break; // End game
        }

        if (game1.isDraw()) // Check for draw
        {
            game1.DisplayBoard(); // Show final board
            std::cout << "OOps! It's a draw!\n"; // Draw
            break; // End game
        }

        // Switch players
        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
}

// Human vs Human game logic
void playGameHumanVsHuman()
{
    TicTacToe game1 = TicTacToe(); // Create game
    int player;                    // Current player
    std::cout << "Do you want to go first? (1 = yes, 2 = no): "; // Ask who goes first
    std::cin >> player;            // Get choice

    int row;
    int col;

    while (true) // Game loop
    {
        game1.DisplayBoard(); // Show board

        std::cout << "Player " << player << " turn .\n";
        std::cout << "Select row (row(0-2): "; // Get row
        std::cin >> row;

        std::cout << "Select column (column(0-2): "; // Get column
        std::cin >> col;

        if (!game1.makeMove(player, row, col)) // Make move
        {
            std::cout << "Invalid Move! Please Try again.\n"; // Invalid move
            continue;
        }

        int winner = game1.whoWin(); // Check for winner
        if (winner != 0)
        {
            game1.DisplayBoard();                           // Show final board
            std::cout << "Player " << winner << " wins!\n"; // Announce winner
            break; // End game
        }

        if (game1.isDraw())
        {
            game1.DisplayBoard(); // Show final board
            std::cout << "OOps! It's a draw!\n"; // Draw
            break; // End game
        }

        // Switch players
        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
}