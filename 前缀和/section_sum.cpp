#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
// #define int long long

using namespace std;
typedef pair<int, int> pii;
const int N = 3e6 + 10;

int a[N], sum[N]; // 前缀和数组

vector<int> num;         // 离散坐标数组
vector<pii> oper, query; // 操作和查询数组

int find(int x)
{
    int l = 0, r = num.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (num[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}

int n, m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int x, c;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> c;
        num.push_back(x);
        oper.push_back({x, c});
    }

    int l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        query.push_back({l, r});
        num.push_back(l);
        num.push_back(r);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    // 去重
    // unique的作用是将重复元素移至容器末尾并返回一个迭代器
    for (auto &it : oper)
    {
        int x = lower_bound(num.begin(), num.end(), it.first) - num.begin();
        // int x2 = find(it.first);
        // cout<<x<<" "<< x2<<endl;
        a[x + 1] += it.second;
    }

    for (int i = 1; i <= num.size(); i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    for (auto &it : query)
    {
        // auto [left,right] = it;
        int left = lower_bound(num.begin(), num.end(), it.first) - num.begin() + 1;
        int right = lower_bound(num.begin(), num.end(), it.second) - num.begin() + 1;
        // cout<<left<<" "<<right<<endl;
        // cout<<find(it.first)<<" "<<find(it.second)<<endl;
        int res = sum[right] - sum[left - 1];
        cout << res << endl;
    }
    return 0;
}
