#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100;
int dist[N][N];
int visit[N];
// int h[N],e[N],ne[N],w[N],idx=0;
// void add(int a,int b ,int t){
// e[idx] = b,ne[idx] = h[a],w[idx] = t,h[a] = idx ++;
// }
int n, k;
void init()
{
    cin >> n >> k;
    int a, b, t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = 0x3f3f3f3f;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> t;
        // add(a,b,t);
        // add(b,a,t)
        dist[a][b] = t;
        dist[b][a] = t;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> visit[i];
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
void solve()
{
    floyd();
    for (int i = 1; i <= k; i++)
    {
        int res = 0;
        int cnt = k - 2;
        int j = 1;
        while (cnt--)
        {
            int d;
            if (j + 1 == i)
            {
                if (j + 2 <= k)
                {
                    d = dist[visit[j]][visit[j + 2]];
                    j += 1;
                    cout << "<" << visit[j] << visit[j + 2] << ">" << endl;
                }
            }
            if (j == i)
            {
                if (j + 2 <= k)
                {
                    d = dist[visit[j + 1]][visit[j + 2]];
                    cout << "<" << visit[j + 1] << visit[j + 2] << ">" << endl;
                    j += 1;
                }
            }
            else
            {
                d = dist[visit[j]][visit[j + 1]];
                j++;
                // res +=d;
                cout << "<" << visit[j] << visit[j + 2] << ">" << endl;
            }
            res += d;
            // cout<<d<<" ";
        }
        // cout<<endl;
        cout << res << " ";
    }
}

int main()
{
    init();
    solve();
    return 0;
}
