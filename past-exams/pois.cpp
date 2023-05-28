#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <set>
#include <string>

using namespace std;

struct PoI {
    int x, y;
    string category;
};

struct Track {
    int x, y;
};

int main() {
    int n, k;
    list<struct PoI> pois;
    list<struct Track> tracks;
    set<string> categories;

    // Read number of PoIs, ensuring that 1 <= N <= 1000
    do {
        cin >> n;
    } while (n < 1 || n > 1000);

    for (int i = 0; i < n; i++) {
        int x, y;
        string c;

        // Read PoI coordinates and category
        cin >> x >> y >> c;

        // Store the struct in a list
        /* PoI p;
        p.x = x;
        p.y = y;
        p.category = c;
        pois.push_back(p); */
        pois.push_back({x, y, c});

        // Store category in a set
        categories.insert(c);
    }

    // Read the number of tracks, ensuring that 1 <= K<= 3000

    do {
        cin >> k;
    } while (k < 1 || k > 3000);

    for (int i = 0; i < k; i++) {
        int x, y;

        // Read track coordinates
        cin >> x >> y;

        // Store the struct in a list
        tracks.push_back({x, y});
    }

    /* list<Track>::iterator it;
    for (it = tracks.begin(); it != tracks.end(); ++it) {
        cout << it->x << " " << it->y << endl;
    } */

    // For each track, find the closest PoI, from each category
    for (auto t : tracks) {
        cout << t.x << " " << t.y << endl;

        // For each category
        for (auto c : categories) {
            double min_dist = INT32_MAX;

            // For each PoI
            for (auto p : pois) {
                // If the PoI is not from the current category, continue
                if (p.category != c) continue;

                // Compute the distance between the track and the PoI
                double dist = sqrt(pow(t.x - p.x, 2) + pow(t.y - p.y, 2));

                // If the distance is smaller than the current minimum
                if (dist < min_dist) {
                    // Update the minimum distance and category
                    min_dist = dist;
                }
            }

            // Print the closest PoI from the current category
            cout << "  " << c << " " << fixed << setprecision(3) << min_dist << endl;
        }
    }

    return 0;
}
