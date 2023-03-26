#include <iostream>

#ifndef CONTEST
#include "babyratio.hpp"
#endif

using namespace std;

// Constructor
rational::rational(int n, int d) {
    int g = gcd(n, d);

    nom = n / g;
    den = d / g;

    if (den < 0) {
        nom = -nom;
        den = -den;
    }
}

rational rational::add(rational r) {
    int n = nom * r.den + den * r.nom;
    int d = den * r.den;

    return rational(n, d);
}

rational rational::sub(rational r) {
    int n = nom * r.den - den * r.nom;
    int d = den * r.den;

    return rational(n, d);
}

rational rational::mul(rational r) {
    return rational(nom * r.nom, den * r.den);
}

rational rational::div(rational r) {
    return rational(nom * r.den, den * r.nom);
}

void rational::print() {
    cout << nom << "/" << den;
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
