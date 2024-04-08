#include <iostream>
using namespace std;

bool check(int z, int m)
{
    if (z == m)
        return false;
    if (z > m)
        return z % m == 1;
    else
        return m % z == 1;
}
int main()

{
    int res = 1;
    for (int i = 1; i <= 2020; i++)
    {
        for (int j = 1; j <= 2020; j++)
        {
            if (check(i, j))
            {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}