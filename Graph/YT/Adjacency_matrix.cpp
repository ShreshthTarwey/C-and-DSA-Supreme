#include<iostream>
#include<vector>
using namespace std;
int main()//TC-> O(n^2) SC->O(n^2)
{
    int vertex,edge;
    cin>>vertex>>edge;
    vector<vector<int>> arr(vertex,vector<int>(vertex,0));
    int u,v,weight;
    for(int i=0;i<edge;i++)
    {
        
        cin>>u>>v>>weight;
        arr[u][v] = weight;
    }
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}