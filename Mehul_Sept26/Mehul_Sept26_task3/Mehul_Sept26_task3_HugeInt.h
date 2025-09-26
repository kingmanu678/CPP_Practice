// Header for HugeInt.
// Header file for HugeInt class.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>

class HugeInt {
    friend std::ostream& operator<<(std::ostream&, const HugeInt&);

public:
    HugeInt(long = 0);
    HugeInt(const char*);

    HugeInt operator+(const HugeInt&) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const char*) const;

private:
    short integer[30];
};

