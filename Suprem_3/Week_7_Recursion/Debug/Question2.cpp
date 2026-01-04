// #include<bits/stdc++.h>

// using namespace std;


// double myPow(double x, int n) {

//        int p = abs(n);
//        double ans = 1.0;
//        while(p>=1){
//           p /= 2 ;
//           x *= x;
//        }
//        return n<0 ? 1/ans : ans;    
//     }

// int subset(int input[], int n, int output[][50], int k) {
//     if(n==0){
//         output[0][0] = 0;
//         return 1;
//     }
    
//     int small = subset(input+1,n-1,output,k);
//     int count = 0;
    
//     for(int i=0;i<small;i++){
//         output[small+count][1] = input[0];
//         int sum = input[0];
//         int l = 0;
//         for(int j=2;output[small-count-1][j-1]!=0;j++){
//             l++;
//             output[small+count][j] = output[small-count-1][j-1];
//             sum = sum + output[small-count-1][j-1];
//         }
//         output[small+count][0] = -1;
//         if(sum==k){
//             output[small+count][0] = l+1;
//         }
//         count++;
//     }
//     return small+count;
// }

// int subsetSumToK(int input[], int n, int output[][50], int k) {
//     int temp[1110000][50];
//     int size = subset(input,n,temp,k);
//     int m=0;
//     for(int i=0;i<size;i++){
//         if(temp[i][0]>0){
//             for(int j=0;j<temp[i][0];j++){
//                 output[m][j] = temp[i][j];
//             }
//         }
//     }
    
//     return m;
// }

#include <iostream>
using namespace std;

/**
 * @brief Helper recursive function.
 * @param output A 2D array to store all subsets.
 * output[i][0] stores the subset's size IF sum == k, otherwise -1.
 * output[i][1...n] stores the elements.
 * @return The total number of subsets (matching or not) found.
 */
int subset(int input[], int n, int output[][50], int k) {
    // Base Case: The input array is empty.
    if (n == 0) {
        // The only subset is the empty set {}.
        output[0][0] = 0; // Its size is 0.
        output[0][1] = 0; // Add a 'terminator' for the copy-loop.
        return 1;         // We found 1 subset.
    }

    // Recursive call: Find all subsets for the rest of the array (n-1 elements).
    // The results are stored in the 'output' array from row 0 to small-1.
    int small = subset(input + 1, n - 1, output, k);

    int count = 0; // Counts the new subsets we are about to create.

    // Iterate through all the subsets we just found (from the recursive call).
    for (int i = 0; i < small; i++) {
        // For each existing subset, create a NEW one by adding input[0] to it.
        // We'll store this new subset at row 'small + count'.
        int new_row = small + count;

        // 1. Add the new element
        output[new_row][1] = input[0]; // First element is the new one
        int sum = input[0];
        int l = 0; // 'l' will count how many elements we copy from the old subset

        // 2. Copy elements from the old subset (output[i])
        //    (The loop that was wrong in the original)
        for (int j = 2; output[i][j - 1] != 0; j++) {
            l++;
            output[new_row][j] = output[i][j - 1]; // *** CORRECTED LINE ***
            sum = sum + output[i][j - 1];
        }
        
        // 3. Add a terminator for the new subset
        output[new_row][l + 2] = 0; // *** NEW FIX ***

        // 4. Check the sum and store the metadata (size or -1)
        output[new_row][0] = -1; // Default to -1 (not a match)
        if (sum == k) {
            output[new_row][0] = l + 1; // It's a match! Store the size (l copied + input[0])
        }
        
        count++; // We've created one new subset
    }

    // Return the total number of subsets
    return small + count; // Old subsets + new subsets
}

/**
 * @brief Main wrapper function.
 * @param output A 2D array to store ONLY the subsets that sum to k.
 * @return The number of subsets that sum to k.
 */
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // A temporary array to hold ALL subsets (good and bad).
    // This size needs to be large enough, e.g., 2^n.
    int temp[10000][50]; 

    // 1. Call the helper to fill 'temp' with all subsets.
    // 'size' will be the total number of subsets (e.g., 2^n).
    int size = subset(input, n, temp, k);

    int m = 0; // 'm' is the row index for our *final* output array.

    // 2. Filter the 'temp' array.
    for (int i = 0; i < size; i++) {
        // Check the metadata in column 0. If it's > 0, the sum was k.
        if (temp[i][0] > 0) {
            // It's a match! Copy it to the final 'output' array.
            for (int j = 0; j < temp[i][0]; j++) {
                // Copy elements from temp[i][1], temp[i][2], ...
                output[m][j] = temp[i][j + 1]; // *** CORRECTED LINE ***
            }
            m++; // *** CORRECTED LINE *** (Move to the next row in 'output')
        }
    }

    // 3. Return the count of *matching* subsets.
    return m; // *** CORRECTED LINE ***
}

int main(){
    // cout<<myPow(2,4);


}