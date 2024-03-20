#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100010;
int p[N];
int dist[N];
int find(int x)
{
    if (p[x] != x)
    {
        int u = find(p[x]);
        dist[x] += dist[p[x]];
        p[x] = u;
    }
    return p[x];
}
int n, k;
int lie = 0;
/*
    判断当前的话和之前的真话是否有矛盾，有以下几种情况：
    1.真话：X,Y是同类，那么假话就是二者不是同类,即X吃Y
        X,Y有共同的祖宗节点，只要find(x)==find(y)
    2.真话：X吃Y,假话就是X和Y是同类,或者Y吃X
*/
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    int d, x, y;
    while (k--)
    {
        cin >> d >> x >> y;
        if (x > n || y > n)
            lie++;
        else
        {
            int px = find(x),py = find(y);
            if (d == 1)
            {
                if (px==py&&(dist[x] - dist[y]) % 3)
                    lie++;
                else if(px!=py)
                {
                    p[px] = py;
                    dist[px] = dist[y] - dist[x];
                }
            }
            if (d == 2)
            {
                if (px==py&&(dist[x] - dist[y] - 1) % 3)
                    lie++;
                else if(px!=py)
                {
                    p[px] = py;
                    dist[px] = dist[y] + 1 - dist[x];
                }
            }
        }
    }
    cout<<lie<<endl;
    return 0;
}