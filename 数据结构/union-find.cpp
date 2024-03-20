#include <iostream>
using namespace std;
const int N = 100010;

int n, m;

int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int a, b;
    char f[2];
    for (int i = 1; i <= m; i++)
    {
        cin >> f >> a >> b;
        if (f[0] == 'M')
            p[find(a)] = find(b);
        if (f[0] == 'Q')
        {
            if (find(a) == find(b))
                cout << "Yes";
            else
                cout << "No";
        }
    }
    return 0;
}