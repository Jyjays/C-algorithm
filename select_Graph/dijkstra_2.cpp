#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define INT_MAX 0x3f3f3f3f

typedef pair<int, int> PII;

const int N = 100010;

int h[N], e[N], w[N], ne[N], idx;
bool st[N];
int n, m;
int dist[N]; // 距离表

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 使用0x3f3f3f3f初始化距离表
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q; //{距离，节点}
     // 这里heap中为什么要存pair呢，首先小根堆是根据距离来排的，所以有一个变量要是距离，
    // 其次在从堆中拿出来的时候要知道知道这个点是哪个点，不然怎么更新邻接点呢？所以第二个变量要存点。
    q.push({0, 1});
    // 这个顺序不能倒，pair排序时是先根据first，再根据second，
                         // 这里显然要根据距离排序
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if (st[u])
            continue;
        st[u] = true;
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > d + w[i])
            {
                dist[j] = d + w[i];
                q.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) // 判断是否可达
        return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra() << endl;
    return 0;
}
