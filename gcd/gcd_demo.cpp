#include <iostream>
#include "gcd.hpp"

using namespace std;

int main()
{
    cout << "Give me two numbers: ";
    int a, b;
    cin >> a >> b;

    cout << "GCD(" << a << ", " << b
         << ") = " << gcd(a, b) << endl;
}
