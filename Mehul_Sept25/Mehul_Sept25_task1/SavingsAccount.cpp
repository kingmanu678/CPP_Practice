#include <iostream>
#include "SavingsAccount.h"

// Initialize static member
double SavingsAccount::annualInterestRate = 0.0;

// Constructor
SavingsAccount::SavingsAccount(const double initialBalance) : savingsBalance(initialBalance) {}

// Get current balance
double SavingsAccount::getBalance() const
{
    return savingsBalance;
}

// Calculate monthly interest
void SavingsAccount::calculateMonthlyInterest()
{
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12; // Calculate interest
    savingsBalance += monthlyInterest; // Add to balance
}

// Set annual interest rate
void SavingsAccount::modifyInterestRate(const double newInterestRate)
{
    annualInterestRate = newInterestRate; // Set new rate
}