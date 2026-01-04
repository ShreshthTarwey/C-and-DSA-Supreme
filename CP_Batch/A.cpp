#include <bits/stdc++.h>
using namespace std;

int main(){


    int n,q;
    cin>>n>>q;
    
    vector<vector<int>> link(n+1);
    for(int i=0;i<n-1;i++){
        int p1,p2;
        cin>>p1>>p2;
        link[p1].push_back(p2);
        link[p2].push_back(p1);
    }

    int logv=20;
    vector<vector<int>> up(logv, vector<int>(n+1,0));
    vector<int> dep(n+1,0);

    queue<int> que;
    que.push(1);
    up[0][1]=1;
    dep[1]=0;

    while(!que.empty()){
        int cur=que.front();
        que.pop();
        for(auto nxt:link[cur]){
            if(nxt==up[0][cur]) continue;
            dep[nxt]=dep[cur]+1;
            up[0][nxt]=cur;
            que.push(nxt);
        }
    }

    for(int i=1;i<logv;i++){
        for(int j=1;j<=n;j++){
            up[i][j]=up[i-1][ up[i-1][j] ];
        }
    }

    auto jump=[&](int node,int step){
        for(int i=0;i<logv;i++){
            if((step>>i)&1) node=up[i][node];
        }
        return node;
    };

    function<int(int,int)> meet=[&](int a,int b){
        if(dep[a]<dep[b]) swap(a,b);
        a=jump(a, dep[a]-dep[b]);
        if(a==b) return a;
        for(int i=logv-1;i>=0;i--){
            if(up[i][a]!=up[i][b]){
                a=up[i][a];
                b=up[i][b];
            }
        }
        return up[0][a];
    };

    auto dist=[&](int x,int y){
        int common=meet(x,y);
        return dep[x]+dep[y]-2*dep[common];
    };

    while(q--){
        int m;
        cin>>m;
        vector<long long> arr(m);
        for(int i=0;i<m;i++) cin>>arr[i];
        if(m==1){
            cout<<0<<"\n";
            continue;
        }
        long long total=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int d=dist((int)arr[i],(int)arr[j]);
                total += 1LL * arr[i] * arr[j] * d;
            }
        }
        cout<<total<<"\n";
    }
}
