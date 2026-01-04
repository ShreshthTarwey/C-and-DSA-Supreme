#include <bits/stdc++.h>
using namespace std;

const int M = 200005;
const int L = 20;

vector<int> g[M], same[M];
int dep[M], jump[M][L], arr[M];
int n;

void dfs(int u, int p) {
    jump[u][0] = p;
    for (int i = 1; i < L; i++) jump[u][i] = jump[jump[u][i - 1]][i - 1];
    for (auto x : g[u]) {
        if (x == p) continue;
        dep[x] = dep[u] + 1;
        dfs(x, u);
    }
}

int findLca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int d = dep[a] - dep[b];
    for (int i = 0; i < L; i++) if ((d >> i) & 1) a = jump[a][i];
    if (a == b) return a;
    for (int i = L - 1; i >= 0; i--) {
        if (jump[a][i] != jump[b][i]) {
            a = jump[a][i];
            b = jump[b][i];
        }
    }
    return jump[a][0];
}

int dist(int a, int b) {
    int c = findLca(a, b);
    return dep[a] + dep[b] - 2 * dep[c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        same[arr[i]].push_back(i);
    }

    dep[1] = 0;
    dfs(1, 1);

    long long ans = 0;
    for (int v = 1; v <= n; v++) {
        auto &grp = same[v];
        if (grp.size() <= 1) continue;
        for (int i = 0; i < (int)grp.size(); i++) {
            for (int j = i + 1; j < (int)grp.size(); j++) {
                ans += dist(grp[i], grp[j]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
