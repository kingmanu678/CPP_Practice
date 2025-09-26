// Main function for task 3.
// Main file for HugeInt operations.
#include <iostream>
#include "Mehul_Sept26_task3_HugeInt.h"

using namespace std;

int main() {
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    cout << "n1 is " << n1 << endl;
    cout << "n2 is " << n2 << endl;
    cout << "n3 is " << n3 << endl;
    cout << "n4 is " << n4 << endl;
    cout << "n5 is " << n5 << endl;

    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << endl;

    cout << n3 << " + " << n4 << " = " << n3 + n4 << endl;

    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << endl;

    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl;

    return 0;
