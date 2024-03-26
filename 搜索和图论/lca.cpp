#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define int long long 
#define dep(x) cout<<#x<<"="<<x<<endl;
#define INT_MAX 0x3f3f3f3f

typedef pair<int,int> pii;
using namespace std;
const int N = 1e6+10;

vector<pii> edges[N];
int fa[N][N];
int dep[N];
int n,m,q;

void add(int u,int v,int w){
    edges[u].push_back(pii(v,w));
    edges[v].push_back(pii(u,w));
}

void dfs(int u,int father){
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    for(int i=1;i<20;i++){
        fa[u][i] = fa[fa[u][i-1]][i-1];//倍增算法
    }
    for(int j = 0; j < edges[u].size(); j++){
        int v = edges[u][j].first;
        if(v != father)
            dfs(v,u);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if(dep[fa[u][i]]> dep[v])
            u = fa[u][i];
    }
    if(u ==v) return u;
    for(int i=19;i>=0;i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
int main(){
    cin>>n>>m>>q;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
    }
}
