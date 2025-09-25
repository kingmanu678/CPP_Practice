#include <iostream>
#include <string>
#include "Card.h"

// Initialize static faces array
const std::string Card::faces[13] = {
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Initialize static suits array
const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Constructor
Card::Card(const int face_of_card, const int suit_of_card) : face(face_of_card), suit(suit_of_card) {}

// Convert card to string
std::string Card::toString() const
{
    std::string cardString = faces[face] + " of " + suits[suit]; // Combine face and suit
    return cardString;
}