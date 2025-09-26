// Header for DoubleScriptedArray.
#ifndef DOUBLE_SCRIPTED_ARRAY_H
#define DOUBLE_SCRIPTED_ARRAY_H

#include <iostream>

class DoubleScriptedArray {
    friend std::istream& operator>>(std::istream&, DoubleScriptedArray&);
    friend std::ostream& operator<<(std::ostream&, const DoubleScriptedArray&);

public:
    DoubleScriptedArray(int = 3, int = 3);
    ~DoubleScriptedArray();

    int getRows() const;
    int getCols() const;

    int& operator()(int, int);
    const int& operator()(int, int) const;

    DoubleScriptedArray& operator=(const DoubleScriptedArray&);
    friend bool operator==(const DoubleScriptedArray&, const DoubleScriptedArray&);
    friend bool operator!=(const DoubleScriptedArray&, const DoubleScriptedArray&);

private:
    int rows;
    int cols;
    int** ptr;
};

