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

    for(int j=1;j<=30;j++){
        for(int i=1;i<=n;i++){
            //Find the 2^j'th parent of node ask for 2^(j-1) the parent
            int firstParent = binaryLifting[i][j-1];
            if(firstParent != -1)
                binaryLifting[i][j] = binaryLifting[firstParent][j-1];
            
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;
        for(int j=30;j>=0;j--){
            // int currPar;
            if((k & (1<<j))){
                x = binaryLifting[x][j];
            }
            if(x == -1){
                // cout<<-1<<" ";
                break;
            } 
        }
        cout<<x<<endl;
    }

}