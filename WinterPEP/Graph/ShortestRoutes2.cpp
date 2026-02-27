#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>>adjMatrix(n+1, vector<int>(n+1, 1e16));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjMatrix[a][b] = min(c, adjMatrix[a][b]);
        adjMatrix[b][a] = min(c, adjMatrix[b][a]);
    }
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j){
                    adjMatrix[i][j] = 0;
                    continue;
                }
                adjMatrix[i][j] = min(adjMatrix[i][via] + adjMatrix[via][j], adjMatrix[i][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<(adjMatrix[a][b] == 1e16 ? -1 : adjMatrix[a][b])<<endl;
    }
    
}