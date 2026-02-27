#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);

    vector<int>inDegree(n+1, 0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int>q;

    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(int neighbour: adj[node]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    if(topo.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto it: topo){
            cout<<it<<" ";
        }
    }
}