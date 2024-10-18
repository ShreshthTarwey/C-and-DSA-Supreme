//  Single File Programming Question

// Problem Statement


// Saru is working as a sales analyst for a retail company. His task is to analyze the sales data and determine the frequency of each product sold during a specific period. Since there are many products piled up together as it is a selling season, she is unable to do everything manually.


// She decided to write a program that calculates the frequency of each product sold. As she is super busy, she is unable to concentrate on writing the code. Help her write the code for the same so that she can report the frequency of each product sold to her head using pointer arithmetic.
// Input format :

// The first line contains an integer n, the number of products sold.

// The second line contains n integers, representing the product IDs of the sold products.
// Output format :

// For each unique element in the array, output a line in the format: "element - count time(s)".

// The output should be in ascending order of the product ID.


// Refer to the sample output for formatting specifications.
// Code constraints :

// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 20

// 1 ≤ product ID ≤ 100
// Sample test cases :
// Input 1 :

// 6
// 15 15 87 985 78 87

// Output 1 :

// 15 - 2 times
// 78 - 1 time
// 87 - 2 times
// 985 - 1 time

// Input 2 :

// 5
// 2 2 2 2 2

// Output 2 :

// 2 - 5 times

// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case. 
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of products sold

    vector<int> productIDs(n); // Vector to store product IDs
    for(int i = 0; i < n; ++i) {
        cin >> productIDs[i]; // Read product IDs
    }

    // Use a map to count frequencies of each product ID
    map<int, int> frequencyMap;
    
    for(int i = 0; i < n; ++i) {
        frequencyMap[productIDs[i]]++; // Increment the count for each product ID
    }

    // Print the output in ascending order of the product IDs
    for(auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        // Output the product ID and its frequency
        if (it->second == 1) {
            cout << it->first << " - 1 time" << endl;
        } else {
            cout << it->first << " - " << it->second << " times" << endl;
        }
    }

    return 0;
}
