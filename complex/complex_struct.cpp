#include <cstdlib>
#include <iostream>

using namespace std;

struct complex   // complex number / μιγαδικός αριθμός
{
    double re;   // real part / πραγματικό μέρος
    double im;   // imaginary part / εικονικό μέρος
};

complex c_make(double r, double i) {
    complex result;
    result.re = r;
    result.im = i;

    return result;
}

complex c_add(complex c1, complex c2) {
    return c_make(c1.re + c2.re, c1.im + c2.im);
}

void c_print(complex c) {
    cout << c.re << " + " << c.im << "i" << endl;
}

int main() {
    complex c1;
    c1.re = 1;
    c1.im = 2;

    complex c2 = {3, 4};

    complex c3 = c_make(5, 6);

    complex c4;
    c4.re = c1.re + c2.re;
    c4.im = c1.im + c2.im;

    complex c5 = c_add(c1, c2);

    c_print(c1);
    c_print(c2);
    c_print(c3);
    c_print(c4);
    c_print(c5);

    return EXIT_SUCCESS;
}
