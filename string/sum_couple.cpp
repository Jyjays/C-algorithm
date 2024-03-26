#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 100010;
ll a[N], b[N];
ll n, m, aim;
int main()
{
    scanf("%d%d%d",&n,&m,&aim);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&b[i]);
    }
    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (j >= 0 && a[i] + b[j] > aim)
            j--;

        if (a[i] + b[j] == aim)
        {
            printf("%d %d\n",i,j);
            break;
        }
    }
    return 0;
}