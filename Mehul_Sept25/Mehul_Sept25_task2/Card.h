#include <string>
#ifndef CARD_H
#define CARD_H

// Card class definition
class Card
{
private:
    int face; // Card face
    int suit; // Card suit

public:
    // Constructor
    Card(const int face_of_Card, const int suit_of_card);

    // Static arrays for faces and suits
    static const std::string faces[13];
    static const std::string suits[4];

    // Return card as a string
    std::string toString() const;
};
#endif