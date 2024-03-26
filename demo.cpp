#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int INM = 0x3f3f3f3f;
typedef pair<int, int> pii;

const int N = 3e5 + 10;

struct Edge
{
    int u, v, w;
    bool operator>(const Edge &e) const
    {
        return w > e.w;
    }
} edge[N];

// unordered_map<pii,int> st;
int ans = 0;
vector<pii> edges[N];
int n, m, q;
int p[N];
int dep[N];      // 深度数组
int cost[N][21]; // 到祖宗节点的最低稳定性
int fa[N][21];
// 最小生成树添加边数函数
void add(int u, int v, int w)
{
    edges[u].push_back(pii(v, w));
    edges[v].push_back(pii(u, w));
}

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
// 最小生成树生成
void kruskal()
{
    for (int i = 0; i < m; i++)
    {
        auto [u, v, w] = edge[i];
        int pa = find(u), pb = find(v);
        if (pa != pb)
        {
            p[pa] = pb;
            add(u, v, w);
        }
    }
}
// lca算法前置操作

void dfs(int u, int father)
{
    dep[u] = dep[father] + 1;
    fa[u][0] = father;

    for (int i = 1; i <= 20; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        cost[u][i] = min(cost[u][i - 1], cost[fa[u][i - 1]][i - 1]);
    }

    int len = edges[u].size();
    for (int i = 0; i < len; i++)
    {
        if (edges[u][i].first != father)
        {
            int nex = edges[u][i].first;
            int w = edges[u][i].second;
            cost[nex][0] = w;
            dfs(nex, u);
        }
    }
}

int lca(int u, int v)
{
    int res = INM;
    if (dep[u] < dep[v])
        swap(u, v);

    for (int i = 20; i >= 0; i--)
    {
        if (dep[fa[u][i]] >= dep[v])
        {
            res = min(res, cost[u][i]);
            u = fa[u][i];
        }
    }
    if (u == v)
        return res;

    for (int i = 20; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
        {
            res = min(res, min(cost[u][i], cost[v][i]));
            u = fa[u][i], v = fa[v][i];
        }
    }

    return min(res, min(cost[u][0], cost[v][0]));
}
int main()
{
    cin >> n >> m >> q;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge[i] = {u, v, w};
    }

    auto cmp = [](Edge e1, Edge e2)
    {
        return e1 > e2;
    };

    sort(edge, edge + m, cmp);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    kruskal();
    dfs(1, 0);

    for (int i = 0; i < q; i++)
    {
        cin >> u >> v;
        if (find(u) != find(v))
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << lca(u, v) << endl;
        }
    }
    return 0;
}