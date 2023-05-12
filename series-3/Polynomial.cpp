#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

class Polynomial {
  protected:
    class Term {
      protected:
        // Fields
        int exponent;
        int coefficient;
        Term *next;
        // Constructor
        Term(int exp, int coeff, Term *n) : exponent(exp), coefficient(coeff), next(n) {}
        friend class Polynomial;

      public:
        // Getters
        int getExponent() const {
            return exponent;
        }

        int getCoefficient() const {
            return coefficient;
        }

        Term *getNext() const {
            return next;
        }
    };

  public:
    // Constructors
    Polynomial() : head(nullptr) {}

    Polynomial(const Polynomial &p) : head(nullptr) {
        copy(p);
    }

    ~Polynomial() {
        purge();
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this != &p) {
            purge();
            copy(p);
        }

        return *this;
    }

    void addTerm(int expon, int coeff) {
        if (coeff == 0) return;

        Term *cur = head;
        Term *prev = nullptr;
        while (cur != nullptr && cur->exponent > expon) {
            prev = cur;
            cur = cur->next;
        }

        if (cur != nullptr && cur->exponent == expon) {
            cur->coefficient += coeff;
            if (cur->coefficient == 0) {
                if (prev == nullptr) {
                    head = cur->next;
                } else {
                    prev->next = cur->next;
                }
                delete cur;
            }
        } else {
            Term *newTerm = new Term(expon, coeff, cur);

            if (prev == nullptr) {
                head = newTerm;
            } else {
                prev->next = newTerm;
            }
        }
    }

    double evaluate(double x) {
        double result = 0;
        Term *cur = head;
        while (cur != nullptr) {
            result += cur->coefficient * pow(x, cur->exponent);
            cur = cur->next;
        }
        return result;
    }

    friend Polynomial operator+(const Polynomial &p, const Polynomial &q) {
        Polynomial result;

        Term *cur_p = p.head, *cur_q = q.head;

        while (cur_p != nullptr || cur_q != nullptr) {
            if (cur_q == nullptr) {
                result.addTerm(cur_p->getExponent(), cur_p->getCoefficient());
                cur_p = cur_p->getNext();
            } else if (cur_p == nullptr) {
                result.addTerm(cur_q->getExponent(), cur_q->getCoefficient());
                cur_q = cur_q->getNext();
            } else if (cur_p->getExponent() > cur_q->getExponent()) {
                result.addTerm(cur_p->getExponent(), cur_p->getCoefficient());
                cur_p = cur_p->getNext();
            } else if (cur_p->getExponent() < cur_q->getExponent()) {
                result.addTerm(cur_q->getExponent(), cur_q->getCoefficient());
                cur_q = cur_q->getNext();
            } else {
                result.addTerm(cur_p->getExponent(),
                               cur_p->getCoefficient() + cur_q->getCoefficient());
                cur_p = cur_p->getNext();
                cur_q = cur_q->getNext();
            }
        }

        return result;
    }

    friend Polynomial operator*(const Polynomial &p, const Polynomial &q) {
        Polynomial result;
        Term *cur_p = p.head;
        while (cur_p != nullptr) {
            Term *cur_q = q.head;
            while (cur_q != nullptr) {
                result.addTerm(cur_p->getExponent() + cur_q->getExponent(),
                               cur_p->getCoefficient() * cur_q->getCoefficient());
                cur_q = cur_q->getNext();
            }
            cur_p = cur_p->getNext();
        }
        return result;
    }

    friend ostream &operator<<(ostream &out, const Polynomial &p) {
        if (p.head == nullptr) {
            out << "0";
            return out;
        }

        Term *cur = p.head;
        bool first = true;
        while (cur != nullptr) {
            if (!first) out << " ";

            if (cur->getCoefficient() < 0) {
                out << "- ";
            } else if (cur->getCoefficient() > 0 && !first) {
                out << "+ ";
            }

            if (abs(cur->getCoefficient()) != 1 || cur->getExponent() == 0) {
                out << abs(cur->getCoefficient());
            }

            if (cur->getExponent() > 0) {
                out << "x";
                if (cur->getExponent() > 1) {
                    out << "^" << cur->getExponent();
                }
            }
            cur = cur->getNext();
            first = false;
        }
        return out;
    }

  private:
    Term *head;

    void purge() {
        Term *cur = head;
        while (cur != nullptr) {
            Term *next = cur->next;
            delete cur;
            cur = next;
        }
        head = nullptr;
    }

    void copy(const Polynomial &p) {
        Term *cur = p.head;
        while (cur != nullptr) {
            addTerm(cur->exponent, cur->coefficient);
            cur = cur->next;
        }
    }
};
