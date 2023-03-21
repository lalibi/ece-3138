#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

// complex number / μιγαδικός αριθμός
class complex {
  public:
    // Constructors / Συνάρτηση κατασκευής
    complex(double r = 0.0, double i = 0.0) {
        re = r;
        im = i;
    }

    // Methods / Μέθοδοι
    double norm() {
        return sqrt(re * re + im * im);
    }

    complex add(complex c) {
        return complex(re + c.re, im + c.im);
    }

    void print(ostream &out = cout) {
        out << re << " + " << im << "i" << endl;
    }

  private:
    // Fields / Πεδία
    double re;   // real part / πραγματικό μέρος
    double im;   // imaginary part / εικονικό μέρος
};

int main() {
    complex c1 = complex(1, 2);
    complex c2 = complex();
    complex c3 = complex(3, 4);

    complex c4 = c1.add(c2);

    c1.print();
    c2.print();
    c3.print();
    c4.print();

    cout << c1.norm() << endl;
    cout << c2.norm() << endl;
    cout << c3.norm() << endl;
    cout << c4.norm() << endl;

    return EXIT_SUCCESS;
}
