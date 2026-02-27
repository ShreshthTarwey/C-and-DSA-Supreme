#include<bits/stdc++.h>
using namespace std;
vector<int>vis;


bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& parents){
    parents[node] = parent;
    vis[node] = 1;
    for(auto ch: adj[node]){
        if(vis[ch]==0){
            // parents[ch] = node;
            if(dfs(ch, node, adj, parents)){
                return true;
            }
        }
        else if(ch != parent){
            vector<int>cycle;
            cycle.push_back(ch);
            int cur = node;
            while(cur != ch){
                cycle.push_back(cur);
                cur = parents[cur];
            }
            cycle.push_back(ch);
            reverse(cycle.begin(), cycle.end());
            cout<<cycle.size()<<endl;
            for(int i: cycle){
                cout<<i<<" ";
            }
            cout<<endl;
            return true;

        }
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vis.resize(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>parents(n+1, -1);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i, -1, adj, parents)){
            return 0;
            }
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;
}