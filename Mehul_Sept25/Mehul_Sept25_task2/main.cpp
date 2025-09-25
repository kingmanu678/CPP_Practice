#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "DeckOfCards.h"

int main()
{
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create and shuffle deck
    DeckOfCards *deck = new DeckOfCards();
    deck->shuffle();

    std::cout << "Shuffled deck — dealing all 52 cards:\n\n";

    // Deal all 52 cards
    int count = 1;
    while (deck->moreCards())
    {
        std::cout << count++ << ". " << deck->dealCard().toString() << "\n"; // Deal and print card
    }

    std::cout << "\nAll cards dealt.\n";

    // Deallocate memory
    delete deck;

    return 0; // Success
}