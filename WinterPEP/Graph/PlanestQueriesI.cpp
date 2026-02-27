#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;

    vector<vector<int>>up(n+1, vector<int>(30, 0));
    up[0][0] = -1;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        up[i][0] = x;
    }

    for(int j=1;j<30;j++){
        for(int i=1;i<=n;i++){
            int intermidate_parent = up[i][j-1];
            up[i][j] = up[intermidate_parent][j-1];
        }
    }

    for(int i=0;i<q;i++){
        int node, k; cin>>node>>k;
        for(int i=30;i>=0;i--){
            if(k & (1ll << i)) node = up[node][i];
        }
        cout<<node<<"\n";
    }
}