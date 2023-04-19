#include <cstdlib>
#include <iostream>

#define N 10000000

using namespace std;

// const int N = 100;

int main() {
    float heights[N];

    for (int i = 0; i < N; i++) {
        heights[i] = 0;
    }

    int n;
    cin >> n;

    // Δυναμική δέσμευση/παραχώρηση μνήμης
    // Αποθήκευση στο heap
    int *weights = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    delete[] weights;

    int *ages = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    free(ages);

    return 0;
}
