#include<bits/stdc++.h>

using namespace std;




int main(){

    string s,t;
    cin>>s>>t;
    //Implementing tabulation
    int n = s.length();
    int m = t.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i] == t[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                int opt1 = dp[i+1][j];
                int opt2 = dp[i][j+1];
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    string res = "";
    int i = 0, j = 0;
    
    // We stop when we hit the end of either string
    while(i < n && j < m){
        if(s[i] == t[j]){
            // Found a match! Add it and move both indices forward
            res += s[i];
            i++;
            j++;
        }
        else{
            // No match. Move in the direction of the larger remaining LCS
            if(dp[i+1][j] >= dp[i][j+1]){
                i++; // Skipping s[i] gives a better or equal result
            }
            else{
                j++; // Skipping t[j] gives a better result
            }
        }
    }
//    reverse(res.begin(), res.end());

   cout<<res;




    // cout<<LCS(s,t,0,0, dp);/
}