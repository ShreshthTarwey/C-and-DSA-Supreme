#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int scores[n];
        int snacks[n];
        
        // Initialize all snacks to 1, since each student must get at least 1 snack
        for (int i = 0; i < n; i++) {
            cin >> scores[i];
            snacks[i] = 1;
        }
        
        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (scores[i] > scores[i-1]) {
                snacks[i] = snacks[i-1] + 1;
            }
        }
        
        // Right to left pass
        for (int i = n-2; i >= 0; i--) {
            if (scores[i] > scores[i+1]) {
                snacks[i] = max(snacks[i], snacks[i+1] + 1);
            }
        }
        
        // Sum up the total snacks required
        int totalSnacks = 0;
        for (int i = 0; i < n; i++) {
            totalSnacks += snacks[i];
        }
        
        cout << totalSnacks << endl;
    }
    
    return 0;
}
