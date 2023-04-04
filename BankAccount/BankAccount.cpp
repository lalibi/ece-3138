#include "BankAccount.hpp"

BankAccount::BankAccount(int a, double b) {
    account_number = a;
    balance = b;
}

void BankAccount ::deposit(double amount) {
    balance += amount;   // balance = balance + amount;
};

void BankAccount ::withdraw(double amount) {
    balance -= amount;   // balance = balance - amount;
};

// Getters
int BankAccount ::get_account_number() {
    return account_number;
};

double BankAccount ::get_balance() {
    return balance;
};

BankAccount operator+(const BankAccount &x, const BankAccount &y) {
    int a = x.account_number + y.account_number;
    int b = x.balance + y.balance;

    return BankAccount(a, b);
};

BankAccount operator-(const BankAccount &x, const BankAccount &y) {
    int a = x.account_number - y.account_number;
    int b = x.balance - y.balance;

    return BankAccount(a, b);
};
