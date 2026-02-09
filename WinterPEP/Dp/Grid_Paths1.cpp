#include<bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
long long recFun(vector<vector<char>>& grid, long long i, long long j, vector<vector<long long>>& dp){
    if(i>=grid.size() || j>=grid[0].size()){
        return 0;
    }
    if(grid[i][j] == '#'){
        return 0;
    }
    if(i==grid.size()-1 && j==grid[0].size()-1){
        return 1;
    }

    if(dp[i][j] != -1) return dp[i][j];


    long long opt1 = recFun(grid, i,j+1, dp);
    long long opt2 = recFun(grid, i+1, j, dp);

    return dp[i][j] = (opt1 + opt2)%MOD;
}

int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m));
    // vector<vector<long long>>dp(n, vector<long long>(m, -1));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    // cout<<recFun(grid, 0,0, dp);


    //Tabulatiion--------------------
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            }
            if(i==n-1 && j==m-1){
                dp[i][j] = 1;
                continue;
            }
            long long opt1 = dp[i+1][j];
            long long opt2 = dp[i][j+1];

            dp[i][j] = (opt1+opt2) %MOD;
        }
    }
    cout<<dp[0][0];
}