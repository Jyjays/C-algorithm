#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int n, ans = N;
int h[N], e[N * 2], ne[N * 2], idx = 0;
bool st[N];

/*start of the add node function*/
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
/*end of the add node function*/

/*start of the dfs function*/
int dfs(int u)
{
    st[u] = true;
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {

            int s = dfs(j);
            res = max(s, res);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}
/*end */
int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
