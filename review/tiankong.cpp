#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
int main()
{
    int n = 23333333;

    int x = 23333333;
    double r = 0;
    while(x>=0)
    {
        double a = x*1.0/n;
        double b = (n - x)*1.0/n;
        // y = n - x;
        r = 0;
        r -= a * log2(a) * x + b * log2(b) * (n-x);
        
        if (fabs(r - 11625907.5798) < 0.0000144654)
        {
            //cout << r<<endl;
            cout << x<<endl;
        }
        x--;
    }
    return 0;
}
