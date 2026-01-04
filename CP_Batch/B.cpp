#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 1e9;
const int LOG = 18;

vector<int> linkList[MAXN];
int depthNode[MAXN], parentJump[LOG][MAXN], sz[MAXN];
bool gone[MAXN], color[MAXN];
int centParent[MAXN];
vector<int> centChild[MAXN];

struct NodeHeap {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
};
NodeHeap heapData[MAXN];

void makeDepth(int u, int p) {
    parentJump[0][u] = p;
    for (int v : linkList[u]) {
        if (v == p) continue;
        depthNode[v] = depthNode[u] + 1;
        makeDepth(v, u);
    }
}

void preLCA(int n) {
    depthNode[1] = 0;
    makeDepth(1, -1);
    for (int i=0;i<LOG-1;i++){
        for (int j=1;j<=n;j++){
            if (parentJump[i][j] == -1) parentJump[i+1][j] = -1;
            else parentJump[i+1][j] = parentJump[i][parentJump[i][j]];
        }
    }
}

int getLCA(int a, int b){
    if (depthNode[a] < depthNode[b]) swap(a,b);
    int diff = depthNode[a] - depthNode[b];
    for (int i=0;i<LOG;i++) if ((diff>>i)&1) a = parentJump[i][a];
    if (a==b) return a;
    for (int i=LOG-1;i>=0;i--){
        if (parentJump[i][a]!=parentJump[i][b]){
            a = parentJump[i][a];
            b = parentJump[i][b];
        }
    }
    return parentJump[0][a];
}

int getDist(int a,int b){
    int c = getLCA(a,b);
    return depthNode[a] + depthNode[b] - 2*depthNode[c];
}

void calcSize(int u,int p){
    sz[u] = 1;
    for (auto v: linkList[u]){
        if (v==p || gone[v]) continue;
        calcSize(v,u);
        sz[u]+=sz[v];
    }
}

int findCent(int u,int p,int total){
    for (auto v: linkList[u]){
        if (v==p || gone[v]) continue;
        if (sz[v] > total/2) return findCent(v,u,total);
    }
    return u;
}

int makeCentroid(int u,int p){
    calcSize(u,-1);
    int cent = findCent(u,-1,sz[u]);
    gone[cent] = true;
    centParent[cent] = p;
    if (p!=-1) centChild[p].push_back(cent);
    for (auto v: linkList[cent]){
        if (!gone[v]) makeCentroid(v,cent);
    }
    return cent;
}

void addColor(int node,bool on){
    int cur=node;
    while(cur!=-1){
        int d = getDist(cur,node);
        if (on) heapData[cur].heap.push({d,node});
        cur = centParent[cur];
    }
}

int getAns(int node){
    int best = INF;
    int cur=node;
    while(cur!=-1){
        while(!heapData[cur].heap.empty()){
            auto top = heapData[cur].heap.top();
            if (!color[top.second]){
                heapData[cur].heap.pop();
                continue;
            }
            best = min(best, top.first + getDist(node,cur));
            break;
        }
        cur = centParent[cur];
    }
    return best==INF?-1:best;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        linkList[a].push_back(b);
        linkList[b].push_back(a);
    }

    preLCA(n);
    makeCentroid(1,-1);

    int q;
    cin>>q;
    while(q--){
        int type,x;
        cin>>type>>x;
        if(type==0){
            color[x] = !color[x];
            addColor(x,color[x]);
        }else{
            cout<<getAns(x)<<"\n";
        }
    }
    return 0;
}
