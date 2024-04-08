#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;

int gra[N][N];
int dist[N]; // 存储i号点到已经被选择的点的集合的最短距离
int n, m;
bool st[N];

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
   // dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))  //判断条件的优先级很重要，首先是不在集合内的，然后再进行筛选
            {
                t = j;
            }
        }
        
        if (i && dist[t] == INF)
            return INF; // 由于t == -1  || dist[j] < dist[t]的存在，可能会将本来就独立的点添加进来

        if (i){
            res += dist[t];
            //cout<<t<<" "<<dist[t]<<endl;
        } // 当i等于0时，各点到集合的距离还没有更新，仍然为INF所以不需要更新结果
        st[t] = true; // 将点加入集合
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], gra[t][j]); // 根据t更新所有点的距离
        }
       
    }
    return res;
}

int main()
{
    cin >> n >> m;
    int a, b, w;
    memset(gra, 0x3f, sizeof gra);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        if (a == b)
            continue;
        gra[a][b] = gra[b][a] = min(gra[a][b], w);
    }
    int res = prim();
    if (res == INF)
        cout << "impossible" << endl;
    else
        cout << res << endl;
    return 0;
}