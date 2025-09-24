#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

// TicTacToe class definition
class TicTacToe
{
private:
    int board[3][3]; // 3x3 game board

public:
    // Constructor
    TicTacToe();

    // Public methods
    void DisplayBoard();                         // Show the board
    bool makeMove(int player, int row, int col); // Make a move
    bool isDraw();                               // Check for a draw
    int whoWin();                                // Check for a winner
    void computerMove();                         // Computer's move
};

#endif