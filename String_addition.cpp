//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int carry = 0;
        int n = s1.length();
        int m = s2.length();
        int i=n-1;
        int j=m-1;
        string res = "";
        while(i>=0 && j>=0){
            int digit1 = s1[i--] - '0';
            int digit2 = s2[j--] - '0';
            int num = digit1+digit2+carry;
            if(num>1 && num<3){
                carry = 1;
                res+='0';
            }
            else if(num==3){
                carry = 1;
                res+='1';
            }
            else{
                carry = 0;
                res+=(char)num;
            }
        }
        while(i>=0){
            int digit = s1[i--] - '0';
            int num = digit + carry;
            if(num==2){
                res+='0';
                carry = 1;
            }
            else{
                res += (num + '0');
                carry = 0;
            }
            // res = res+s1[i--];
        }
        while(j>=0){
            int digit = s2[j--] - '0';
            int num = digit + carry;
            if(num==2){
                res+='0';
                carry = 1;
            }
            else{
                res += (num + '0');
                carry = 0;
            }
            // res = res+s2[j--];
        }
        if(carry==1){
            res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

// Add Binary Strings
// Difficulty: MediumAccuracy: 23.25%Submissions: 88K+Points: 4
// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Input: s1 = "1101", s2 = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100
// Input: s1 = "00100", s2 = "010"
// Output: 110
// Explanation: 
//   100
// +  10
//   110
// Constraints:
// 1 ≤s1.size(), s2.size()≤ 106

// Company Tags
// AmazonMicrosoftFacebook
// Topic Tags
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us k