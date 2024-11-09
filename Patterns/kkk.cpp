#include <iostream>
#include <vector>
using namespace std;

int calculateScore(const vector<string>& grid) {
    int score = 0;

    // Loop through each cell in the 10x10 grid
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 'X') {
                // Check the ring based on row and column indices
                if (i == 0 || j == 0 || i == 9 || j == 9) {
                    score += 1;  // Outermost ring
                } else if (i == 1 || j == 1 || i == 8 || j == 8) {
                    score += 2;  // Fourth ring
                } else if (i == 2 || j == 2 || i == 7 || j == 7) {
                    score += 3;  // Third ring
                } else if (i == 3 || j == 3 || i == 6 || j == 6) {
                    score += 4;  // Second ring
                } else if (i == 4 || j == 4 || i == 5 || j == 5) {
                    score += 5;  // Innermost ring
                }
            }
        }
    }
    return score;
}

int main() {
    int t;
    cin >> t;  // Read number of practice sessions
    while (t--) {
        vector<string> grid(10);
        for (int i = 0; i < 10; ++i) {
            cin >> grid[i];  // Read each row of the grid
        }
        cout << calculateScore(grid) << endl;  // Calculate and print the score
    }
    return 0;
}
