#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "DeckOfCards.h"
#include "Utilities.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random

    // Create and shuffle deck
    DeckOfCards deck;
    deck.shuffle();

    // Create two player hands
    std::vector<Card> player1Hand;
    std::vector<Card> player2Hand;

    // Deal 5 cards to each player
    for (int i = 0; i < 5; ++i)
    {
        player1Hand.push_back(deck.dealCard());
        player2Hand.push_back(deck.dealCard());
    }

    // Print hands
    printHand(player1Hand, "Player 1");
    printHand(player2Hand, "Player 2");

    // Evaluate player 1's hand
    int score1 = 1; // Default score
    if (hasFourOfAKind(player1Hand))
        score1 = 7;
    else if (isFlush(player1Hand))
        score1 = 6;
    else if (hasThreeOfAKind(player1Hand))
        score1 = 4;
    else if (hasTwoPairs(player1Hand))
        score1 = 3;
    else if (hasPair(player1Hand))
        score1 = 2;

    // Evaluate player 2's hand
    int score2 = 1; // Default score
    if (hasFourOfAKind(player2Hand))
        score2 = 7;
    else if (isFlush(player2Hand))
        score2 = 6;
    else if (hasThreeOfAKind(player2Hand))
        score2 = 4;
    else if (hasTwoPairs(player2Hand))
        score2 = 3;
    else if (hasPair(player2Hand))
        score2 = 2;

    // Determine winner
    std::cout << "Result: ";
    if (score1 > score2)
        std::cout << "Player 1 wins!\n"; // Player 1 wins
    else if (score2 > score1)
        std::cout << "Player 2 wins!\n"; // Player 2 wins
    else
        std::cout << "It's a tie!\n"; // Tie

    return 0; // Success
}