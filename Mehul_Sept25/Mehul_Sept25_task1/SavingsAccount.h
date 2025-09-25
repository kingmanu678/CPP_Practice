#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

// SavingsAccount class definition
class SavingsAccount
{
private:
    static double annualInterestRate; // Annual interest rate
    double savingsBalance;            // Account balance

public:
    // Constructor
    SavingsAccount(const double initialBalance);

    // Public methods
    void calculateMonthlyInterest(); // Calculate monthly interest
    static void modifyInterestRate(double newInterestRate); // Set interest rate
    double getBalance() const; // Get balance
};

#endif