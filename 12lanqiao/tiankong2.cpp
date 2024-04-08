#include <iostream>
#define int long long
using namespace std;
signed main()
{
    int count = 0;
    int n = 202104182210418;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (n % (i * j) == 0)
        {
            count++;
            j++;
        }
    }
    cout << count;
    return 0;
}