#include <iostream>
#include "Account.h"

Account::Account(int initialBalance) {
    if (initialBalance >= 0) {
        balance = initialBalance;
    } else {
        balance = 0;
        std::cout << "Error: Initial balance cannot be negative. Balance set to 0." << std::endl;
    }
}

void Account::credit(int amount) {
    balance += amount;
}

void Account::debit(int amount) {
    if (amount > balance) {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    } else {
        balance -= amount;
    }
}

int Account::getBalance() const {
    return balance;
}