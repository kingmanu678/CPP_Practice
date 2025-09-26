// Main function for task 2.
#include <iostream>
#include "Mehul_Sept26_task2_Complex.h"

using namespace std;

int main() {
    Complex a(1.0, 7.0), b(9.0, 2.0), c;

    cout << "Enter a complex number in the form (a, b): ";
    cin >> c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;

    //-Check
    if (a == c) {
        cout << "a and c are equal" << endl;
    } else {
        cout << "a and c are not equal" << endl;
    }

    return 0;
