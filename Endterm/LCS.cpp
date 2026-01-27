#include<bits/stdc++.h>

using namespace std;


int LCS(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
    if(i>=s1.length() || j>=s2.length()){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + LCS(s1,s2,i+1,j+1, dp);
    }

    int opt1 = LCS(s1, s2, i+1, j, dp);
    int opt2 = LCS(s1, s2, i, j+1, dp);
    return dp[i][j] = max(opt1, opt2);
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
    cout<<LCS(s1,s2,0,0,dp);
}