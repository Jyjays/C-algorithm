#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

struct Edge
{ // 使用结构体存储边，不用定义一大堆数组去加边
    int a;
    int b;
    int w;
} e[M]; // 把每个边保存下来即可
int dist[N];
int back[N]; // 备份数组防止串联
int n, m, k; // k代表最短路径最多包涵k条边

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist); // dist初始化位无穷，八字节3f3f3f3f大于1e9
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    { // k次循环
        memcpy(back, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        { // 遍历所有边，而dijkstra是遍历所有顶点n*n
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], back[a] + w);
            // 使用backup:避免给a更新后立马更新b, 这样b一次性最短路径就多了两条边出来
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d", dist[n]);
    return 0;
}
