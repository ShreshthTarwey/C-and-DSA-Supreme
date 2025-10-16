#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
    }
    
}