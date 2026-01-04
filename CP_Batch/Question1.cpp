#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> g[N];
int a[N];
long long ans;

int dfs(int u, int p, int val, long long &res) {
    int cnt = (a[u] == val);
    for (int v : g[u]) {
        if (v == p) continue;
        int sub = dfs(v, u, val, res);
        res += 1LL * sub * (cnt - sub);
        cnt += sub;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) mp[a[i]].push_back(i);

    long long total = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        int val = it->first;
        vector<int> nodes = it->second;
        vector<int> vis(n + 1, 0);
        for (int x : nodes) vis[x] = 1;
        long long res = 0;
        dfs(nodes[0], 0, val, res);
        total += res;
    }

    cout << total << "\n";
}
