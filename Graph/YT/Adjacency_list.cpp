#include<iostream>
#include<vector>
using namespace std;
int main()
{   //Undirected unweighted graph
    // int vertex,edge;
    // cin>>vertex>>edge;
    // vector<int> arr[vertex];
    // int u,v;
    // // cin>>u>>v;
    // for(int i=0;i<edge;i++){
    //     cin>>u>>v;
    //     arr[u].push_back(v);
    //     arr[v].push_back(u);
    // }
    // for(int i=0;i<vertex;i++){
    //     cout<<i<<" -> ";
    //     for(int j=0;j<arr[i].size();j++)
    //     {
    //         cout<<"("<<arr[i][j]<<")";
    //     }
    //     cout<<endl;

    // }


    //undirected weighted
    // int vertex,edge;
    // cin>>vertex>>edge;
    // vector<pair<int,int>> arr[vertex];
    // int u,v;
    // // cin>>u>>v;
    // int weight;
    // for(int i=0;i<edge;i++){
    //     cin>>u>>v>>weight;
    //     arr[u].push_back(make_pair(v,weight));
    //     arr[v].push_back(make_pair(u,weight));
    // }
    // for(int i=0;i<vertex;i++){
    //     cout<<i<<" -> ";
    //     for(int j=0;j<arr[i].size();j++)
    //     {
    //         cout<<"("<<arr[i][j].first<<", "<<arr[i][j].second<<")";
    //     }
    //     cout<<endl;

    // }
    //Directed unWeighted
    // int vertex,edge;
    // cin>>vertex>>edge;
    // vector<int> arr[vertex];
    // int u,v;
    // for(int i=0;i<edge;i++)
    // {
    //     cin>>u>>v;
    //     arr[u].push_back(v);
    // }
    // for(int i=0;i<vertex;i++)
    // {
    //     cout<<i<<" -> ";
    //     for(int j=0;j<arr[i].size();j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //directed weighted
    int vertex,edge;
    cin>>vertex>>edge;
    vector<pair<int,int>> arr[vertex];
    int u,v,weight;
    for(int i=0;i<edge;i++){
        cin>>u>>v>>weight;
        arr[u].push_back(make_pair(v,weight));
    }
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<"("<<arr[i][j].first<<", "<<arr[i][j].second<<")"<<" ";
        }
        cout<<endl;
    }
}