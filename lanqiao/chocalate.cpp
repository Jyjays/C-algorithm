#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> pii;

const int N = 100010;
int n, k;
pii cho[N];

// 参数：巧克力，边长
// 返回块数
int cut(pii c, int l)
{
    auto [h, w] = c;
    if (l > h || l > w)
        return 0;
    int curh = h / l, curw = w / l;
    // if ((curh + 1) * l <= h)
    //     curh++;
    // if ((curw + 1) * l <= w)
    //     curw++;

    //  cout<<"width:"<<l<<" "<<"count:"<<curh*curw<<endl;
    return curh * curw;
}
int check(int l)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += cut(cho[i], l);
    }
    return sum;
}
int find()
{
    int maxc = 0;
    int left = 1, right = N;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (check(mid) < k)
        {
            right = mid - 1;
        }
        else if (check(mid) >= k)
        {
            maxc = max(maxc, mid);
            left = mid + 1;
        }
    }
    return maxc;
}

signed main()
{
    cin >> n >> k;
    int h, w;
    for (int i = 1; i <= n; i++)
    {
        cin >> h >> w;
        cho[i] = {h, w};
    }
    // auto cmp = [](pii a, pii b)
    // {
    //     return a.first * a.second < b.first * b.second;
    // };
    // sort(cho, cho + n, cmp);
    cout << find() << endl;
    return 0;
}