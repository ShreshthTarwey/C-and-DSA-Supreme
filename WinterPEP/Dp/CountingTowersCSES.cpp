#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000005;
long long int dp[N][2] = {0};
// long long dp[N][2];
// int recFun(int level, int type){
//     if(level == N) return 1;
//     if(dp[level][type] != -1) return dp[level][type];
//     long long ans = 0;
//     if(type == 0){
//         ans+=(2ll*recFun(level+1, 0)) + recFun(level + 1, 1);
//     }
//     else{
//         ans += (4ll * recFun(level+1, 1)) + recFun(level + 1, 0);
//     }
//     return dp[level][type] = (ans)%MOD;
// }

int main(){
    // Recursive method -----Stak overflow_error is coming
    // memset(dp, -1, sizeof dp);
    // recFun(0, 0); recFun(0, 1);
    
    //Iterative
    //Base Case
    dp[0][1] = 1;
    dp[0][0] = 1;
    for(int i=1;i<N;i++){
        dp[i][0] = (2ll* dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1] = (4ll* dp[i-1][1] + dp[i-1][0])%MOD;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n-1][0] + dp[n-1][1])%MOD<<endl;
    }


    





}