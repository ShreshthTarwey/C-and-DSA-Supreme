#include<bits/stdc++.h>

using namespace std;

int recFun(vector<vector<int>>& matrix, int i, int lastIndex, vector<vector<int>>& dp){
    if(i>=matrix.size()){
        return 0;
    }

    if(dp[i][lastIndex+1]!=-1) return dp[i][lastIndex+1];

    int maxHappi = INT_MIN;

    for(int col = 0;col<3;col++){
        if(lastIndex!=col){
            // lastIndex = col;
            maxHappi = max(maxHappi, matrix[i][col] + recFun(matrix, i+1, col, dp));
        }
    }
    return dp[i][lastIndex+1] = maxHappi;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>matrix(n, vector<int>(3,0));
    vector<vector<int>>dp(n, vector<int>(4,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<recFun(matrix, 0,-1, dp);
}