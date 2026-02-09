#include<bits/stdc++.h>

using namespace std;



int recFun(vector<int>& arr, int index, int n, int k, vector<int>& dp){
    if(index==n-1) return 0;
    if(index>n) return 1e6;
    if(dp[index]!=-1) return dp[index];
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        if(index+i<arr.size())
        ans = min(ans, abs(arr[index] - arr[index+i])+recFun(arr, index+i, n, k, dp));
    }
    return dp[index] = ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);
    vector<int>dp(n,-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<recFun(arr,0,n,k, dp);
}