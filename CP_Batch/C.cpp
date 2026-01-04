#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int MAXN = 200005;

int n, q;
long long A[MAXN], Fv[MAXN];
long long nzProd[MAXN]; 
int zeroCnt[MAXN];      
int parnt[MAXN];
vector<int> children[MAXN];

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
long long inv(long long x) { return modpow(x, MOD - 2); }

void build(int u) {
    if (children[u].empty()) {
        nzProd[u] = 1;    
        zeroCnt[u] = 0;
        Fv[u] = A[u] % MOD;
        return;
    }
    long long prod = 1;
    int zc = 0;
    for (int v : children[u]) {
        build(v);
        if (Fv[v] == 0) {
            zc++;
        } else {
            prod = (prod * Fv[v]) % MOD;
        }
    }
    nzProd[u] = prod;
    zeroCnt[u] = zc;
    long long effective = (zeroCnt[u] > 0 ? 0 : nzProd[u]);
    Fv[u] = (A[u] + effective) % MOD;
}

void cascade_update(int node, long long newA) {

    long long oldF = Fv[node];
    A[node] = newA % MOD;

    
    long long effective = (zeroCnt[node] > 0 ? 0 : nzProd[node]);
    if (children[node].empty()) {
        Fv[node] = A[node] % MOD;
    } else {
        Fv[node] = (A[node] + effective) % MOD;
    }

    long long curOld = oldF;
    long long curNew = Fv[node];
    int p = parnt[node];

    while (p != 0) {
        
        if (curOld == 0 && curNew == 0) {
            
        } else if (curOld == 0 && curNew != 0) {
            zeroCnt[p]--;
            nzProd[p] = (nzProd[p] * curNew) % MOD;
        } else if (curOld != 0 && curNew == 0) {
            zeroCnt[p]++;
            nzProd[p] = (nzProd[p] * inv(curOld)) % MOD;
        } else { 
            nzProd[p] = nzProd[p] * curNew % MOD * inv(curOld) % MOD;
        }

        long long prevF = Fv[p];
        long long eff = (zeroCnt[p] > 0 ? 0 : nzProd[p]);
        Fv[p] = (A[p] + eff) % MOD;


        curOld = prevF;
        curNew = Fv[p];
        node = p;
        p = parnt[node];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        cin >> parnt[i];
        children[parnt[i]].push_back(i);
    }
    parnt[1] = 0;

    for (int i = 1; i <= n; ++i) cin >> A[i];


    build(1);

    while (q--) {
        int v; long long x;
        cin >> v >> x;
        cascade_update(v, x);
        cout << Fv[1] % MOD << '\n';
    }
    return 0;
}
