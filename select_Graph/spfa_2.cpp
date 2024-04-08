#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], w[N], idx = 0;
int n, m;
int dist[N];
int cnt[N];//记录所有点的入队次数
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    //printf("h[%d]=%d\n",a,h[a]);
}

bool spfa()
{
 
    queue<int> q;
    for(int i=1;i<=n;i++){
        st[i] = true;
        q.push(i);
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
      
        st[t] = false; // 出队
        for (int i = h[t]; i != -1; i = ne[i])
        {
          
            int data = e[i];
             
            if (dist[data] > dist[t] + w[i])
            {
                dist[data] = dist[t] + w[i];
                cnt[data] = cnt[t] +1;  
                if(cnt[data]>=n) return true;
                
                if (!st[data])
                {
                    q.push(data);
                    st[data] = true;
                }
            }
        }
    }
    return false;
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
    if(spfa()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}