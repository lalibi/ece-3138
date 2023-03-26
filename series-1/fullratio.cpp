#include <iostream>

#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

// Constuctor
rational::rational(int n, int d) {
    int g = gcd(n, d);

    nom = n / g;
    den = d / g;

    if (den < 0) {
        nom = -nom;
        den = -den;
    }
}

// Operator overloading
rational operator+(const rational &x, const rational &y) {
    int n = x.nom * y.den + x.den * y.nom;
    int d = x.den * y.den;

    return rational(n, d);
}

rational operator-(const rational &x, const rational &y) {
    int n = x.nom * y.den - x.den * y.nom;
    int d = x.den * y.den;

    return rational(n, d);
}

rational operator*(const rational &x, const rational &y) {
    return rational(x.nom * y.nom, x.den * y.den);
}

rational operator/(const rational &x, const rational &y) {
    return rational(x.nom * y.den, x.den * y.nom);
}

ostream &operator<<(ostream &out, const rational &x) {
    out << x.nom << "/" << x.den;
    return out;
}

int rational::gcd(int a, int b) {
    // Euclid's algorithm
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}
