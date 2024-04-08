#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
const int N = 100010;

int n, m, k;
vector<int> edges[N];
set<int> cnt;
map<pii, int> lk;
int p[N];
int res = 1;

void add(int a, int b)
{
    lk[{a, b}] = 1;
    lk[{b, a}] = 1;
}

// 并查集函数
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

void Link()
{
    cnt.clear();
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (auto i : lk)
    {
        // 如果两个点之间是连通的那么就加入同一个集合中
        if (i.second)
        {
            auto [s, e] = i.first;
            int ps = find(s), pe = find(e);
            p[pe] = ps;
        }
    }
    for (auto i : lk)
    {
        // 将所有点所属集合加入cnt集合中
        cnt.insert(find(i.first.first));
        cnt.insert(find(i.first.second));
    }
    cout << cnt.size() << " ";
}

void Break(int a, int b)
{
    // 将两点断开
    lk[{a, b}] = 0;
    lk[{b, a}] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int s, e;
    // 输入连通的点
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> e;
        add(s, e);
    }
    // 输入要断开的点
    int a, b;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        Break(a, b);
        // 断开后重新连接，并计算不同的点的集合数
        Link();
    }

    return 0;
}
