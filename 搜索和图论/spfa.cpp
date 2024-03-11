#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], w[N], idx = 0;
int n, m;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    printf("h[%d]=%d\n",a,h[a]);
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] =0;
    queue<int> q;
    q.push(1);
    st[1] = true; // u点已经进入队列中
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        //cout<<t<<" "<<h[t]<<endl;
        st[t] = false; // 出队
        for (int i = h[t]; i != -1; i = ne[i])
        {
          
            int data = e[i];
            //printf("debug:%d dist= %d data[t] = %d,\n",data,dist[data],dist[t]);
            if (dist[data] > dist[t] + w[i])
            {
                dist[data] = dist[t] + w[i];

               // printf("debug:%d dist= %d ",data,dist[data]);
                if (!st[data])
                {
                    q.push(data);
                    st[data] = true;
                }
            }
        }
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main()
{
    cin >>n>> m;
    memset(h, -1, sizeof h);

    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    int res = spfa();
    if (res == -1)
        cout << "impossible" << endl;
    else
        cout << res << endl;
    return 0;
}