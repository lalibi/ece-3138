#include <iostream>

#include "BankAccount.hpp"

using namespace std;

int main() {
    BankAccount a(1, 100);
    BankAccount b(2, 200);

    BankAccount c = a + b;
    BankAccount d = a - b;

    cout << c.get_account_number() << " " << c.get_balance() << endl;
    cout << d.get_account_number() << " " << d.get_balance() << endl;

    return 0;
}
