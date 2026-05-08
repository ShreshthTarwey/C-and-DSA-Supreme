#include <bits/stdc++.h>
using namespace std;

class DSU {
    // These are private by default, which is good practice
    vector<int> parent, rank;

public: // You need 'public:' so main() can access these functions
    
    // Constructor
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 1. Normal Union (Naive approach)
    void unionNormal(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Arbitrarily make rootX the parent of rootY
            parent[rootY] = rootX; 
        }
    }

    // 2. Union by Rank (Optimized approach)
    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Attach the smaller rank tree under the larger rank tree
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                // If ranks are equal, pick one as the root and increase its rank
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
}; // <-- Added the required semicolon here

int main() {
    int n = 5; 
    
    // Create a DSU object for 5 elements (0 through 4)
    DSU dsu(n);

    // Let's test the functions
    dsu.unionByRank(0, 1);
    dsu.unionByRank(2, 3);
    
    // You can use either union function, though unionByRank is faster for large datasets
    dsu.unionNormal(1, 2); 

    // Check if 0 and 3 are now connected
    if (dsu.find(0) == dsu.find(3)) {
        cout << "0 and 3 are in the same set." << endl;
    } else {
        cout << "0 and 3 are in different sets." << endl;
    }

    return 0;
}