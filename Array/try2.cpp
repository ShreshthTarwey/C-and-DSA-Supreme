#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int a[n], t[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    int initialConcepts = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            initialConcepts += a[i];
            a[i] = 0; // Setting a[i] to 0 since these concepts are already counted
        }
    }
    
    // Now we use a sliding window technique to find the best k-minute segment
    int maxExtraConcepts = 0, currentExtraConcepts = 0;
    
    for (int i = 0; i < k; i++) {
        currentExtraConcepts += a[i];
    }
    
    maxExtraConcepts = currentExtraConcepts;
    
    for (int i = k; i < n; i++) {
        currentExtraConcepts += a[i] - a[i - k];
        maxExtraConcepts = max(maxExtraConcepts, currentExtraConcepts);
    }
    
    cout << initialConcepts + maxExtraConcepts << endl;
    
    return 0;
}
