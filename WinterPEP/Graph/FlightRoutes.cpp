#include<bits/stdc++.h>

using namespace std;

#define int long long int
int32_t main(){
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<int> dist(n+1, 1e18);
    vector<int> cnt(n+1, 0);
    dist[1] = 0;
    vector<int>ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0,1});
    // cnt[1] = 1;
    while(pq.size()){
        int node = pq.top().second;
        int nodeCost = pq.top().first;
        if(cnt[node]>k){
            pq.pop();
            continue;
        }
        if(node == n){
            ans.push_back(nodeCost);
            if(ans.size() == k) break; 
        }
        pq.pop();
        cnt[node] += 1;
        for(auto it: adj[node]){
            int ch = it.first;
            int cost = it.second;
            pq.push({nodeCost + cost, ch});
            // cnt[ch] += 1;
        }
    }
    for(int i=1;i<=ans.size();i++){
        cout<<ans[i-1]<<" ";
    }
}