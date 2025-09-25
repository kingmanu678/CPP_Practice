#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

#include "DeckOfCards.h"

// Constructor: Initialize 52 cards
DeckOfCards::DeckOfCards() : currentCard(0)
{
    for (int suit = 0; suit < 4; suit++)
    {
        for (int face = 0; face < 13; face++)
        {
            deck.push_back(Card(face, suit)); // Add card to deck
        }
    }
}

// Shuffle the deck
void DeckOfCards::shuffle()
{
    for (int i = 0; i < deck.size(); i++)
    {
        int random = std::rand() % deck.size(); // Get random index
        std::swap(deck[i], deck[random]);      // Swap cards
    }

    currentCard = 0; // Reset current card
}

// Deal a card from the deck
Card DeckOfCards::dealCard()
{
    if (moreCards())
    {
        return deck[currentCard++]; // Return next card
    }
    else
    {
        std::cout << "Error! No cards to deal...\n"; // Error message
        return Card(0, 0); // Return default card
    }
}

// Check if there are more cards to deal
bool DeckOfCards::moreCards() const
{
    if (currentCard < deck.size())
    {
        return true; // More cards available
    }
    else
    {
        return false; // No more cards
    }
}