#include <iostream>
#include "Account.h"

int main() {
    Account account1(1000);
    Account account2(-500);

    std::cout << "Account1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account2 balance: " << account2.getBalance() << std::endl;

    account1.credit(500);
    std::cout << "Account1 balance after credit: " << account1.getBalance() << std::endl;

    account1.debit(200);
    std::cout << "Account1 balance after debit: " << account1.getBalance() << std::endl;

    account2.debit(100);
    std::cout << "Account2 balance after attempting to debit: " << account2.getBalance() << std::endl;

    return 0;
}