#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, -4};
    int n = arr.size();
    
    // Loop for the starting point of the subarray
    for (int i = 0; i < n; i++) {
        // Loop for the ending point of the subarray
        for (int j = i; j < n; j++) {
            // Loop to print each element in the subarray from i to j
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";  // print arr[k], not arr[i]
            }
            cout << endl;  // Print newline after printing each subarray
        }
    }
    
    return 0;
}
