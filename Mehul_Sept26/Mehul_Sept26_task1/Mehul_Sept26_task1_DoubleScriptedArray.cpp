// Double scripted array implementation.
//-Function
#include "Mehul_Sept26_task1_DoubleScriptedArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

DoubleScriptedArray::DoubleScriptedArray(int r, int c) {
    rows = r > 0 ? r : 1;
    cols = c > 0 ? c : 1;
    ptr = new int*[rows];
    //-Loop
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[cols];
    }
}

int& DoubleScriptedArray::operator()(int r, int c) {
    //-Check
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw out_of_range("Subscript out of range");
    }
    return ptr[r][c];
}

const int& DoubleScriptedArray::operator()(int r, int c) const {
    //-Check
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw out_of_range("Subscript out of range");
    }
    return ptr[r][c];
}

DoubleScriptedArray::~DoubleScriptedArray() {
    //-Loop
    for (int i = 0; i < rows; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

int DoubleScriptedArray::getRows() const {
    return rows;
}

int DoubleScriptedArray::getCols() const {
    return cols;
}

DoubleScriptedArray& DoubleScriptedArray::operator=(const DoubleScriptedArray& right) {
    //-Check
    if (this == &right) {
        return *this;
    }
    //-Loop
    for (int i = 0; i < rows; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
    rows = right.rows;
    cols = right.cols;
    ptr = new int*[rows];
    //-Loop
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[cols];
    }
    //-Loop
    for (int i = 0; i < rows; i++) {
        //-Loop
        for (int j = 0; j < cols; j++) {
            ptr[i][j] = right.ptr[i][j];
        }
    }
    return *this;
}

bool operator==(const DoubleScriptedArray& left, const DoubleScriptedArray& right) {
    //-Check
    if (left.rows != right.rows || left.cols != right.cols) {
        return false;
    }
    //-Loop
    for (int i = 0; i < left.rows; i++) {
        //-Loop
        for (int j = 0; j < left.cols; j++) {
            //-Check
            if (left.ptr[i][j] != right.ptr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const DoubleScriptedArray& left, const DoubleScriptedArray& right) {
    return !(left == right);
}

istream& operator>>(istream& input, DoubleScriptedArray& a) {
    //-Loop
    for (int i = 0; i < a.rows; i++) {
        //-Loop
        for (int j = 0; j < a.cols; j++) {
            input >> a.ptr[i][j];
        }
    }
    return input;
}

ostream& operator<<(ostream& output, const DoubleScriptedArray& a) {
    //-Loop
    for (int i = 0; i < a.rows; i++) {
        //-Loop
        for (int j = 0; j < a.cols; j++) {
            output << a.ptr[i][j] << ' ';
        }
        output << endl;
    }
    return output;
}