#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(n,0));
    //undirectional
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u,v;
            cin>>u>>v;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }
    //Directional
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u,v;
            cin>>u>>v;
            matrix[u][v] = 1;
            // matrix[v][u] = 1;
        }
    }
    //Weighted,undirectional
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u,v,w;
            cin>>u>>v>>w;
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
    }
    //Weighted Directional
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u,v,w;
            cin>>u>>v>>w;
            matrix[u][v] = w;
            // matrix[v][u] = w;
        }
    }
}