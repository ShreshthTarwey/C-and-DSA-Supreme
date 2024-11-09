#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int calculateScore(const vector<string>& grid) {
    int score = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 'X') {
                // Calculate Manhattan distance from the center (4,4)
                int distance = max(abs(i - 4), abs(j - 4));
                // Add points based on the distance
                score += (5 - distance);
            }
        }
    }
    return score;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> grid(10);
        for (int i = 0; i < 10; ++i) {
            cin >> grid[i];
        }
        cout << calculateScore(grid) << endl;
    }
    return 0;
}
