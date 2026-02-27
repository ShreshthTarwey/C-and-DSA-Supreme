#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<int> dist(n+1, 1e18);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0,1});
    while(pq.size()){
        int node = pq.top().second;
        if(pq.top().first>dist[node]){
            pq.pop();
            continue;
        }
        pq.pop();
        for(auto it: adj[node]){
            int ch = it.first;
            int cost = it.second;
            if(dist[node] + cost < dist[ch]){
                dist[ch] = dist[node] + cost;
                pq.push({dist[ch], ch});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}