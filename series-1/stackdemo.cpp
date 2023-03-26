#include <iostream>

using namespace std;

template <typename T>
class stack {
  public:
    // Constructor
    stack(int size) {
        data = new T[size];
        // data = (int *)malloc(size * sizeof(int));
        top = 0;
        maxSize = size;
    }

    // Copy constructor
    stack(const stack &s) {
        data = new T[s.maxSize];
        top = s.top;
        maxSize = s.maxSize;

        for (int i = 0; i < s.top; i++) {
            data[i] = s.data[i];
        }
    }

    // Destructor
    ~stack() {
        delete[] data;
    }

    // Assignment operator overload
    const stack &operator=(const stack &s) {
        if (this != &s) {
            delete[] data;

            data = new T[s.maxSize];
            top = s.top;
            maxSize = s.maxSize;

            for (int i = 0; i < s.top; i++) {
                data[i] = s.data[i];
            }
        }

        return *this;
    }

    bool empty() {
        if (top == 0)
            return true;
        else
            return false;

        // return (top == 0);
    }

    void push(const T &x) {
        data[top] = x;
        top++;

        // data[top++] = x;
    }

    T pop() {
        top--;
        return data[top];

        // return data[--top];
    }

    int size() {
        return top;
    }

    // Overload the << operator
    friend ostream &operator<<(ostream &out, const stack &s) {
        out << "[";
        for (int i = 0; i < s.top; i++) {
            if (i > 0) out << ", ";
            out << s.data[i];
        }
        out << "]";

        return out;
    }

  private:
    T *data;
    int top;
    int maxSize;
};

#ifndef CONTEST
int main() {
    // let's play with integers...
    stack<int> s(10);
    cout << "s is empty: " << s << endl;
    s.push(42);
    cout << "s has one element: " << s << endl;
    s.push(17);
    s.push(34);
    cout << "s has more elements: " << s << endl;
    cout << "How many? " << s.size() << endl;

    stack<int> t(5);
    t.push(7);
    cout << "t: " << t << endl;
    t = s;
    cout << "popping from s: " << s.pop() << endl;
    s.push(8);

    stack<int> a(s);
    t.push(99);
    a.push(77);

    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    cout << "a: " << a << endl;

    // now with doubles...
    stack<double> c(4);
    c.push(3.14);
    c.push(1.414);
    cout << "c contains doubles " << c << endl;

    // and with characters...
    stack<char> k(4);
    k.push('$');
    cout << "k contains a character " << k << endl;
}
#endif
