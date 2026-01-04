#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 17;
struct SegNode {
    int left, right, count;
} treeSeg[40 * MAXN];

int n, m; 
int val[MAXN];
int parentUp[MAXN][MAXLOG];
int deep[MAXN];
int versionRoot[MAXN];
int totalNodes = 0;
vector<int> adj[MAXN];
vector<int> allVals;
int makeTree(int l, int r) {
    int now = ++totalNodes;
    treeSeg[now].count = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        treeSeg[now].left = makeTree(l, mid);
        treeSeg[now].right = makeTree(mid + 1, r);
    }
    return now;
}
int addValue(int oldVer, int l, int r, int pos) {
    int now = ++totalNodes;
    treeSeg[now] = treeSeg[oldVer];
    treeSeg[now].count++;
    if (l == r) return now;
    int mid = (l + r) / 2;
    if (pos <= mid)
        treeSeg[now].left = addValue(treeSeg[oldVer].left, l, mid, pos);
    else
        treeSeg[now].right = addValue(treeSeg[oldVer].right, mid + 1, r, pos);
    return now;
}
int findKth(int verU, int verV, int verLca, int verParLca, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) / 2;

    int cntLeft = treeSeg[ treeSeg[verU].left ].count
                + treeSeg[ treeSeg[verV].left ].count
                - treeSeg[ treeSeg[verLca].left ].count
                - treeSeg[ treeSeg[verParLca].left ].count;

    if (k <= cntLeft)
        return findKth(treeSeg[verU].left, treeSeg[verV].left,
                       treeSeg[verLca].left, treeSeg[verParLca].left, l, mid, k);
    else
        return findKth(treeSeg[verU].right, treeSeg[verV].right,
                       treeSeg[verLca].right, treeSeg[verParLca].right,
                       mid + 1, r, k - cntLeft);
}
void dfsMake(int node, int par) {
    parentUp[node][0] = par;
    deep[node] = deep[par] + 1;

    int index = lower_bound(allVals.begin(), allVals.end(), val[node]) - allVals.begin() + 1;
    versionRoot[node] = addValue(versionRoot[par], 1, allVals.size(), index);

    for (int nxt : adj[node]) {
        if (nxt != par)
            dfsMake(nxt, node);
    }
}
int getLca(int a, int b) {
    if (deep[a] < deep[b]) swap(a, b);
    int diff = deep[a] - deep[b];

    for (int i = 0; i < MAXLOG; i++) {
        if ((diff >> i) & 1)
            a = parentUp[a][i];
    }

    if (a == b) return a;

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (parentUp[a][i] != parentUp[b][i]) {
            a = parentUp[a][i];
            b = parentUp[b][i];
        }
    }
    return parentUp[a][0];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        allVals.push_back(val[i]);
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

    versionRoot[0] = makeTree(1, allVals.size());
    dfsMake(1, 0);

    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            parentUp[i][j] = parentUp[ parentUp[i][j - 1] ][j - 1];
        }
    }

    while (m--) {
        int a, b, k;
        cin >> a >> b >> k;
        int lca = getLca(a, b);
        int plca = parentUp[lca][0];
        int pos = findKth(versionRoot[a], versionRoot[b], versionRoot[lca], versionRoot[plca],
                          1, allVals.size(), k);
        cout << allVals[pos - 1] << "\n";
    }

    return 0;
}
