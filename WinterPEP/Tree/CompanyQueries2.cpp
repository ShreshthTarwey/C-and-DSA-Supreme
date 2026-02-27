#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>binaryLifting(n+1, vector<int>(31,-1));
    // adj.resize(n+1);
    for(int i=2;i<=n;i++){
        int a;  cin>>a;
        // i is the first boss/parent of a
        binaryLifting[i][0] = a;
    }

    

}