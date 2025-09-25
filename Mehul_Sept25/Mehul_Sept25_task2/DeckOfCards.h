#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include <vector>
#include "Card.h"

// DeckOfCards class definition
class DeckOfCards
{
private:
    std::vector<Card> deck; // Vector of cards
    int currentCard;        // Index of the next card to be dealt

public:
    // Constructor
    DeckOfCards();

    // Public methods
    void shuffle();      // Shuffle the deck
    Card dealCard();     // Deal a card
    bool moreCards() const; // Check if there are more cards
};

#endif