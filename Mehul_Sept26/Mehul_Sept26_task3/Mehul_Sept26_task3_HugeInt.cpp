// HugeInt implementation.
// Implementation of HugeInt class.
//-Function
#include "Mehul_Sept26_task3_HugeInt.h"
#include <cstring>

HugeInt::HugeInt(long value) {
    //-Loop
    for (int i = 0; i < 30; i++) {
        integer[i] = 0;
    }
    //-Loop
    for (int j = 29; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const char* string) {
    //-Loop
    for (int i = 0; i < 30; i++) {
        integer[i] = 0;
    }
    int len = strlen(string);
    //-Loop
    for (int j = 30 - len, k = 0; j < 30; j++, k++) {
        //-Check
        if (isdigit(string[k])) {
            integer[j] = string[k] - '0';
        }
    }
}

HugeInt HugeInt::operator+(const HugeInt& op2) const {
    HugeInt temp;
    int carry = 0;
    //-Loop
    for (int i = 29; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        //-Check
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return temp;
}

HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+(const char* op2) const {
    return *this + HugeInt(op2);
}

std::ostream& operator<<(std::ostream& output, const HugeInt& num) {
    int i;
    //-Loop
    for (i = 0; (num.integer[i] == 0) && (i <= 29); i++);
    //-Check
    if (i == 30) {
        output << 0;
        return output;
    }
    //-Loop
    for (; i <= 29; i++) {
        output << num.integer[i];
    }
    return output;
