#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;

int n, m;
int h[N], e[N * 2], ne[N * 2], idx = 0;
int color[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
            return false;
    }

    return true;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
            }
        }
    }

    if (!flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}