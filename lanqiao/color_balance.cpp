#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
unordered_map<int, int> c_num;
const int N = 200010;
int n;
int count = 0; // 满足条件的子树
// int back[N] ; // 保存某种颜色的个数
int h[N], e[N], ne[N], c[N], idx = 0;
// bool st[N];
void add(int a, int b, int color)
{
    e[idx] = b, ne[idx] = h[a], c[idx] = color, h[a] = idx++;
}
void add2par(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool is_ans(unordered_map<int, int> &m)
{
    int firstValue = m.begin()->second;
    for (auto &kv : m)
    {
        if (kv.second != firstValue)
        {
            return false;
        }
    }
    return true;
}

void dfs(int u, unordered_map<int, int> &m, int &count)
{
    if (h[u] == -1)
    {
        count++;
        m[c[u]]++;
        cout<<u<<" "<< m[c[u]]<<endl;
        return;
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(e[j], m, count);
        m[c[j]]++;
        cout<<j<<" "<< m[c[j]]<<endl;
        if (is_ans(m))
            count++;
    }
}

int main()
{
    cin >> n;
    int color, par;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        cin >> color >> par;
        add(par, i, color);
        // add2par(i,par);
    }
    int res = 0;
    dfs(1, c_num, res);
    cout << res << endl;
    return 0;
}