#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 13;
int n, m, k;
int res = 0;
int mp[N][N];

void dfs(int x, int y, int cnt, int maxv)
{

    int v = mp[x][y];
    if (x > n || y > m)
    {
        return;
    }
    if (x == n && y == m)
    {
        if (cnt == k)
        {
            res++;
        }
        //到达终点但是还没有处理终点位置的数据
        else if(cnt == k-1&&v>maxv){
            res++;
        }
        else
        {
            return;
        }
    }

    
    if (v > maxv)
    {
        dfs(x + 1, y, cnt + 1, v);
        dfs(x, y + 1, cnt + 1, v);
        // dfs(x + 1, y, cnt, maxv);
        // dfs(x, y + 1, cnt, maxv);
    }
    dfs(x + 1, y, cnt, maxv);
    dfs(x, y + 1, cnt, maxv);
} 
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j= 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    dfs(1, 1, 0, 0);
    cout << res << endl;
    return 0;
}