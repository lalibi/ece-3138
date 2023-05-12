#include <stdio.h>
#include <stdlib.h>

#include "Polynomial.cpp"

using namespace std;

int main() {
    Polynomial p;       // 0
    cout << p << endl;
    p.addTerm(1, 3);    // 3x
    cout << p << endl;
    p.addTerm(2, 1);    // x^2
    cout << p << endl;
    p.addTerm(0, -1);   // -1
    cout << p << endl;

    cout << "--------------------------------------------------" << endl;

    Polynomial q(p);    // x^2 + 3x - 1
    cout << q << endl;
    q.addTerm(1, -3);   // -3x
    cout << q << endl;

    cout << "--------------------------------------------------" << endl;

    cout << "P(x) = " << p << endl;
    cout << "P(1) = " << p.evaluate(1) << endl;
    cout << "Q(x) = " << q << endl;
    cout << "Q(1) = " << q.evaluate(1) << endl;
    cout << "(P + Q)(x) = " << p + q << endl;
    cout << "(P * Q)(x) = " << p * q << endl;

    cout << "--------------------------------------------------" << endl;

    p.addTerm(2, -1);
    cout << p << endl;
    p.addTerm(1, -3);
    cout << p << endl;
    p.addTerm(0, 2);
    cout << p << endl;
    p.addTerm(0, -1);
    cout << p << endl;

    cout << "--------------------------------------------------" << endl;

    Polynomial p1;
    p1.addTerm(6, -22);
    p1.addTerm(10, 1);
    p1.addTerm(2, 4);
    cout << "P(x) = " << p1 << endl;
    cout << "P(0) = " << p1.evaluate(0) << endl;
    cout << "P(1) = " << p1.evaluate(1) << endl;
    cout << "P(3) = " << p1.evaluate(3) << endl;
    cout << "P(-8) = " << p1.evaluate(-8) << endl;

    Polynomial q1;
    q1.addTerm(1, 3);
    q1.addTerm(2, -9);
    q1.addTerm(1, 5);
    q1.addTerm(0, 7);
    cout << "Q(x) = " << q1 << endl;
    cout << "Q(0) = " << q1.evaluate(0) << endl;
    cout << "Q(1) = " << q1.evaluate(1) << endl;
    cout << "Q(3) = " << q1.evaluate(3) << endl;
    cout << "Q(-8) = " << q1.evaluate(-8) << endl;

    Polynomial pq = p1 + q1;

    cout << "(P + Q)(x) = " << pq << endl;
    cout << "(P + Q)(0) = " << pq.evaluate(0) << endl;
    cout << "(P + Q)(1) = " << pq.evaluate(1) << endl;
    cout << "(P + Q)(3) = " << pq.evaluate(3) << endl;
    cout << "(P + Q)(-8) = " << pq.evaluate(-8) << endl;
}
