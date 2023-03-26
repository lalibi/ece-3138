#include <iostream>

#include "babyratio.hpp"

using namespace std;

int main() {
    rational a(1, 2);   // rational a = rational(1,2);
    rational b(3, 4);
    rational c(5, 6);

    a.add(b).sub(c).print();
    cout << endl;
    a.print();

    cout << " should still be 1/2" << endl;

    cout << endl;

    rational x1(1, 3);
    rational y1(1, 4);
    x1.add(y1).print();
    cout << endl;

    rational x2(2, 3);
    rational y2(12, 7);
    x2.mul(y2).print();
    cout << endl;

    rational x3(3, 8);
    rational y3(-2, 11);
    x3.div(y3).print();
    cout << endl;

    return EXIT_SUCCESS;
}
