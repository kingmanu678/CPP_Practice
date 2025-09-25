#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include "Card.h"

// Poker hand evaluation functions
bool hasPair(const std::vector<Card> &hand);           // Check for a pair
bool hasTwoPairs(const std::vector<Card> &hand);        // Check for two pairs
bool hasThreeOfAKind(const std::vector<Card> &hand);    // Check for three of a kind
bool hasFourOfAKind(const std::vector<Card> &hand);     // Check for four of a kind
bool isFlush(const std::vector<Card> &hand);            // Check for a flush
bool isStraight(const std::vector<Card> &hand);         // Check for a straight
void printHand(const std::vector<Card> &hand, const std::string &playerName); // Print a player's hand

#endif