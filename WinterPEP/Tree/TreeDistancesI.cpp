#include<bits/stdc++.h>

using namespace std;
vector<vector<int>>adj;
vector<int>down, up;


void dfs(int node, int parent){
    for(auto child: adj[node]){
        if(child!=parent){
            dfs(child, node);
            down[node] = max(down[node], 1+down[child]);
        }
    }

}

void dfsReRoot(int node, int parent){
    int max1 = -1;
    int max2 = -1;

    for(auto child: adj[node]){
        if(child == parent) continue;
        if(down[child] +1 >max1){
            max2 = max1;
            max1 = 1+ down[child];
        }
        else if(down[child] + 1>max2){
            max2 = 1 + down[child];
        }

    }
    int use = max1;
    for(auto child: adj[node]){
        if(child == parent) continue;

        if(down[child] + 1 == max1) use = max2;
        up[child] = max(up[child], 1 + use);
        dfsReRoot(child, node);
    }
}

int main(){
    int n; cin>>n;  
    adj.resize(n+1); down.resize(n+1); up.resize(n+1);

    for(int i=1;i<n;i++){
        // a is the boss for i
        int a; cin>>a;
        int b; cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    dfsReRoot()
    for(int i=1;i<=n;i++){
        cout<<i<<"->"<<down[i]<<" "<<up[i]<<endl;
    }
}