#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

// #define int long long
using namespace std;
const int N = 1e6 + 10;
const int F = -1e4;
int n;
typedef pair<int, int> pii;
pii child[N];
int nodes[N];

int check_ch(int l, int r)
{
    if (nodes[l] != nodes[r])
        return F;
    if (l == -1 && r == -1)
        return 0;
    int res = 2;
    res += check_ch(child[l].first, child[r].second) + check_ch(child[l].second, child[r].first);
    return res;
}
int check(int u)
{
    int cnt = 1;
    if (child[u].first == -1 && child[u].second == -1)
    {
        return cnt;
    }
    cnt += check_ch(child[u].first, child[u].second);
    return cnt;
}
int bfs()
{
    int res = -1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int d = q.front();
        q.pop();
        int cnt = check(d);
        if (cnt > 0)
        {
            res = max(cnt,res);
        }
        if (child[d].first != -1)
        {
            q.push(child[d].first);
        }
        if (child[d].second != -1)
        {
            q.push(child[d].second);
        }
    }
    return res;
}

void solve()
{
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i];
    }
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        child[i] = {l, r};
    }

    res = bfs();

    cout << res;
}
int main()
{
    solve();
    return 0;
}