#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int dist[N];   // 距离表
int gra[N][N]; // 邻接矩阵
bool st[N];    // 判断是否已经被遍历过

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int t = -1; // 距离已经遍历过的点最近的点
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        st[t] = true; // 已找到最近的点
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + gra[t][j]); // 根据距离最近的点更新最短距离
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(gra, 0x3f, sizeof gra);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        gra[x][y] = min(gra[x][y], z); // 因为可能有重边，只需要保留最短的一条就可以
    }

    cout << dijkstra() << endl;
    return 0;
}