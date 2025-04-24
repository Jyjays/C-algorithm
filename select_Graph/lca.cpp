#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

// #define int long long
#define dep(x) cout << #x << "=" << x << endl;
#define INT_MAX 0x3f3f3f3f

using namespace std;
typedef pair<int, int> pii;
const int N = 1e6 + 10;

vector<pii> edges[N];  // 邻接表存储图
int fa[N][N];          // 祖先节点，fa[i][j]表示从i出发，向上走2^j步的节点
int dep[N];            // 深度
int n, m, q;           // 节点数，边数，询问数

void add(int u, int v, int w) {
  edges[u].push_back(pii(v, w));
  edges[v].push_back(pii(u, w));
}

void dfs(int u, int father) {
  fa[u][0] = father;         // 初始化父节点
  dep[u] = dep[father] + 1;  // 初始化深度
  for (int i = 1; i < 20; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];  // 倍增算法，
  }
  for (int j = 0; j < edges[u].size(); j++) {
    int v = edges[u][j].first;
    if (v != father) dfs(v, u);
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[fa[u][i]] > dep[v]) u = fa[u][i]; // 将u上移到与v同一深度
  }
  if (u == v) return u;             // 如果u和v相同，直接返回u

  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {     // 一直向上移动，直到找到第一个不同的祖先
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  return fa[u][0];
}
int main() {
  cin >> n >> m >> q;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    add(u, v, w);
  }
}
