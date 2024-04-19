#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n, a, b;
int t = 0, B = 0x3f3f3f3f;
vector<pii> m;
// 求V的最xiao值，保证生产不大于当前值
bool checkb(int v)
{
    for (auto &i : m)
    {
        if (i.first / v > i.second)
        {
            return false;
        }
    }
    return true;
}
// 求V的最大值，保证生产不少于当前值
bool checkt(int v)
{
    for (auto &i : m)
    {
        if (i.first / v < i.second)
        {
            return false;
        }
    }
    return true;
}
void bfmax()
{
    int l = 0, r = 1e6;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (checkt(mid))
        {
            t = max(mid, t);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}
void bfmin()
{
    int l = 0, r = 1e6;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (checkb(mid))
        {
            B = min(mid, B);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        m.push_back({a, b});
    }
    bfmin();
    bfmax();
    cout << B << " " << t;
}
int main()
{
    cin >> n;

    solve();

    return 0;
}