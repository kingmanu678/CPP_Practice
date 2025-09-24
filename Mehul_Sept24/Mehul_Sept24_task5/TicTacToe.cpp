#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>
#include "TicTacToe.h"

// Constructor: Initialize board to 0
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

// Display the game board
void TicTacToe::DisplayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Make a move on the board
bool TicTacToe::makeMove(int player, int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3) // Check bounds
    {
        return false; // Out of bounds
    }
    if (board[row][col] != 0) // Check if cell is empty
    {
        return false; // Cell not empty
    }

    board[row][col] = player; // Place move

    return true; // Valid move
}

// Check for a winner
int TicTacToe::whoWin()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        // Check columns
        if (board[0][i] != 0 && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
        {
            return board[0][i]; // Return winner
        }

        // Check rows
        if (board[i][0] != 0 && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
        {
            return board[i][0]; // Return winner
        }
    }

    // Check diagonals
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0]; // Return winner

    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2]; // Return winner

    return 0; // No winner
}

// Check for a draw
bool TicTacToe::isDraw()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == 0)
                return false; // Not a draw
    return whoWin() == 0; // Is a draw if no winner
}

// Computer makes a random move
void TicTacToe::computerMove()
{
    int row, col;
    do
    {
        row = rand() % 3; // Random row
        col = rand() % 3; // Random col
    } while (board[row][col] != 0); // Loop until empty cell is found
    board[row][col] = 2; // Place computer's move
}