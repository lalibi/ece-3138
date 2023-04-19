#include <cstdlib>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p1 = {1, 2};
    Point p2 = {3, 4};

    Point *pp = &p2;

    cout << "p1 = (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    p1.y = 5;
    pp->x = 6;   // (*pp).x = 6;

    cout << "p1 = (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    return EXIT_SUCCESS;
}
