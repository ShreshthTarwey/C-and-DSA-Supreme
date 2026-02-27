#include<bits/stdc++.h>

using namespace std;
vector<vector<int>>adj;


int deepChild = -1, maxHeight = 0;

void dfs(vector<vector<int>>& adj, int node, int parent){
    cout<<node<<" ";
    for(auto ch: adj[node]){
        if(ch != parent){
            dfs(adj, ch, node);
        }
    }
}

void height(int node, int parent, int level){
    if(level>maxHeight){
        maxHeight = level;
        deepChild = node;
    }
    // maxHeight = max(maxHeight, level);
    // if(adj[node].size()==1) return;

    for(auto ch: adj[node]){
        if(ch != parent){
            height(ch, node, level+1);
        }
    }
    return; 
}

int main(){
    int n;
    cin>>n;

    adj.resize(n+1);

    for(int i=2;i<=n;i++){
        int a; cin>>a;
        int b; cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    height(1, 0, 0);
    height(deepChild, 0, 0);
    cout<<maxHeight;

}