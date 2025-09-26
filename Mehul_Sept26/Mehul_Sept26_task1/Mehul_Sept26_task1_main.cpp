// Main function for task 1.
#include <iostream>
#include "Mehul_Sept26_task1_DoubleScriptedArray.h"

using namespace std;

int main() {
    DoubleScriptedArray a(3, 3);
    cout << "Enter 9 integers for the array:" << endl;
    cin >> a;
    cout << "The array is:" << endl;
    cout << a;

    cout << "a(1, 1) is " << a(1, 1) << endl;
    a(1, 1) = 100;
    cout << "a(1, 1) is now " << a(1, 1) << endl;

    DoubleScriptedArray b = a;
    cout << "b is:" << endl;
    cout << b;

    //-Check
    if (a == b) {
        cout << "a and b are equal" << endl;
    } else {
        cout << "a and b are not equal" << endl;
    }

    b(0, 0) = 0;
    cout << "b is now:" << endl;
    cout << b;

    //-Check
    if (a != b) {
        cout << "a and b are not equal" << endl;
    } else {
        cout << "a and b are equal" << endl;
    }

    return 0;
