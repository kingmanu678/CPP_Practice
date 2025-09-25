#include <iostream>
#include "SavingsAccount.h"

int main()
{
    // Create two savings accounts
    SavingsAccount *saver1 = new SavingsAccount(2000.0);
    SavingsAccount *saver2 = new SavingsAccount(3000.0);

    // Print initial balances
    std::cout << "Initial Balance of saver1: $" << saver1->getBalance() << std::endl;
    std::cout << "Initial Balance of saver2: $" << saver2->getBalance() << std::endl;

    // Set interest rate to 3%
    SavingsAccount::modifyInterestRate(3.0);
    std::cout << "\nAnnual Interest Rate is set to 3 percent.\n\n";

    // Calculate and print new balances
    saver1->calculateMonthlyInterest();
    std::cout << "New Balances of saver1: $" << saver1->getBalance() << std::endl;

    saver2->calculateMonthlyInterest();
    std::cout << "New Balances of saver2: $" << saver2->getBalance() << std::endl;

    // Set interest rate to 4%
    SavingsAccount::modifyInterestRate(4.0);
    std::cout << "\nAnnual Interest Rate is set to 4 percent.\n\n";

    // Calculate and print new balances
    saver1->calculateMonthlyInterest();
    std::cout << "New Balances of saver1: $" << saver1->getBalance() << std::endl;

    saver2->calculateMonthlyInterest();
    std::cout << "New Balances of saver2: $" << saver2->getBalance() << std::endl;

    // Deallocate memory
    delete saver1;
    delete saver2;
    return 0; // Success
}