#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> BFS(int v,vector<int>arr[]){
    vector<bool> visited(v,0);
    vector<int>ans;
    queue<int> q;
    visited[3] = 1;
    q.push(3);
    int node;
    while(!q.empty())
    {   
        // if(!visited[arr[]])
        node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<arr[node].size();i++)
        {
            if(!visited[arr[node][i]])
            {
                q.push(arr[node][i]);
                visited[arr[node][i]] = 1;
            }
        }
    }
    return ans;
}
void DFS(int node,vector<int>&ans,vector<int>&visited,vector<int>arr[])
{
    ans.push_back(node);
    visited[node] = 1;
    for(int i=0;i<arr[node].size();i++)
    {
        if(!visited[arr[node][i]])
        DFS(arr[node][i],ans,visited,arr);
    }
}
vector<int> depthFirstSearch(int v,vector<int>arr[])
{
    vector<int>visited(v,0);
    vector<int>ans;
    // queue<int>q;
    visited[0] = 1;
    DFS(0,ans,visited,arr);
    return ans;
}
int main()
{
    int vertex,edge;
    cout<<"Enter the number of edge and vertex: ";
    cin>>vertex>>edge;
    vector<int> arr[vertex];
    int u,v;
    for(int i=0;i<edge;i++)
    {
        cout<<"Enter edge "<<i+1<<" ";
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> ans = BFS(vertex,arr);
    cout<<"BFS: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    ans = depthFirstSearch(vertex,arr);
    cout<<"DFS: ";
    for(int i=0;i<vertex;i++)
    {
        cout<<ans[i]<<" ";
    }
}