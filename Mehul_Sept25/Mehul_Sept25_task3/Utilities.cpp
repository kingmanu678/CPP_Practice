#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "Utilities.h"

// Helper function to count face frequencies
std::map<int, int> Facefrequency(const std::vector<Card> &hand)
{
    std::map<int, int> map_face; // Map to store frequencies
    for (int i = 0; i < hand.size(); i++)
    {
        map_face[hand[i].getFace()]++; // Increment frequency
    }
    return map_face;
}

// Check for a pair
bool hasPair(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Get frequencies
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 2)
        {
            return true; // Found a pair
        }
    }
    return false; // No pair
}

// Check for two pairs
bool hasTwoPairs(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Get frequencies
    int pairCount = 0;
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 2)
        {
            pairCount++; // Increment pair count
        }
    }
    if (pairCount == 2)
    {
        return true; // Found two pairs
    }
    else
    {
        return false; // Not two pairs
    }
}

// Check for three of a kind
bool hasThreeOfAKind(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Get frequencies
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 3)
        {
            return true; // Found three of a kind
        }
    }
    return false; // No three of a kind
}

// Check for four of a kind
bool hasFourOfAKind(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Get frequencies
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 4)
        {
            return true; // Found four of a kind
        }
    }
    return false; // No four of a kind
}

// Check for a flush
bool isFlush(const std::vector<Card> &hand)
{
    int suit = hand[0].getSuit(); // Get suit of first card
    for (const Card &card : hand)
    {
        if (card.getSuit() != suit)
        {
            return false; // Not a flush
        }
    }
    return true; // Is a flush
}

// Check for a straight (not implemented)
// bool isStraight(const std::vector<Card> &hand);

// Print a player's hand
void printHand(const std::vector<Card> &hand, const std::string &playerName)
{
    std::cout << playerName << "'s hand:\n";
    for (const Card &card : hand)
    {
        std::cout << "  " << card.toString() << "\n";
    }
    std::cout << std::endl;
}