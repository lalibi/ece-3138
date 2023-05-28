#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;
    queue<int> q;
    stack<int> s;

    // Read number of integers, ensuring that 1 <= N <= 10000
    do {
        cin >> n;
    } while (n < 1 || n > 10000);

    for (int i = 0; i < n; i++) {
        int x;

        // Read integer
        cin >> x;

        // Store integer in a queue
        q.push(x);
    }

    // Read a sequence of chars like PQSPQQPSPSSP
    // a differenct operatin for each one char
    // Q: Dequeue an element from the queue and push it into the stack
    // S: Pop an element from the stack and enqueue it into the queue
    // P: Print the elemenets of the queue
    // If an operation vcannot be made the word "error" must be printed

    // Read the sequence of chars
    string seq;
    cin >> seq;

    for (char &c : seq) {
        switch (c) {
        case 'Q':
            if (q.empty()) {
                cout << "error" << endl;
                exit(1);
            } else {
                int x = q.front();
                q.pop();
                s.push(x);
            }
            break;
        case 'S':
            if (s.empty()) {
                cout << "error" << endl;
                exit(1);
            } else {
                int x = s.top();
                s.pop();
                q.push(x);
            }
            break;
        case 'P':
            // Print the queue elements without removing them
            // We need to copy the queue to print it
            queue<int> tmp = q;
            while (!tmp.empty()) {
                cout << tmp.front();
                tmp.pop();
                if (!tmp.empty()) cout << " ";
            }
            cout << endl;
            break;
        }
    }

    return 0;
}
