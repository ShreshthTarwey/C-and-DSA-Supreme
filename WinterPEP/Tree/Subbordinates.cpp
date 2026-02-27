#include<bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adj, int node, int parent, vector<int>& ans){
    // cout<<node<<" ";
    if(adj[node].size() == 0) return 0;
    int counter = 0;
    for(auto ch: adj[node]){
        // if(ch != parent){

            counter += 1 + dfs(adj, ch, node, ans);
        // }
    }
    ans[node] = counter;
    return counter;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>>adj(n+1);

    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        // adj[i].push_back(a);
        adj[a].push_back(i);
    }
    vector<int>ans(n+1);
    dfs(adj, 1, -1, ans);
    // reverse(ans.begin(), ans.end());
    for(int i=1;i<=ans.size()-1;i++){
        cout<<ans[i]<<" ";
    }
}