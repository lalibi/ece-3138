#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "ChessBoardArray.cpp"

using namespace std;

int main() {
    ChessBoardArray a(4, 1);   // size 4x4, rows and columns numbered from 1
    a[3][1] = 42;
    a[4][4] = 17;
    try {
        a[2][1] = 7;
    } catch (out_of_range &e) {
        cout << "a[2][1] is black" << endl;
    }
    try {
        cout << a[1][2] << endl;
    } catch (out_of_range &e) {
        cout << "and so is a[1][2]" << endl;
    }
    cout << a;
}
