#include <iostream>

class Account {
public:
    Account(int initialBalance);
    void credit(int amount);
    void debit(int amount);
    int getBalance() const;

private:
    int balance;
};