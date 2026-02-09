#include<bits/stdc++.h>

using namespace std;


int recFun(vector<int>& arr, int index, int target, vector<int>& dp){
    if(index==target) return 0;
    if(dp[index]!=-1) return dp[index];
    int option1 = abs(arr[index] - arr[index+1]) + recFun(arr, index+1, target, dp);
    int option2 = INT_MAX;
    if(index+2<=target){
        option2 = abs(arr[index] - arr[index+2]) + recFun(arr, index+2, target, dp);
    }
    return dp[index] = min(option1, option2);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n, 0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n, -1);
    cout<<recFun(arr, 0, n-1, dp);
}