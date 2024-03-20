#include <iostream>
#include <algorithm>
using namespace std;

const int N = 40;
typedef long long ll;
int ans = 50;
int n;
ll m;
ll weight[N], Sum[N];

void dfs(ll sum, int i, int count)
{
    // cout<<sum<<" "<<count<<endl;
    if (count >= ans)
        return;
    if (sum == m){
        ans = count;
        return ;  //更新值后就要返回
    }
       

     if (i >= n || sum > m || sum + Sum[i] < m)
        return;             //已经无法再进行递归

    dfs(sum + weight[i], i + 1, count);
    dfs(sum + (weight[i] >> 1), i + 1, count + 1);
    dfs(sum, i + 1, count);
}

int main()
{
    cin >> n >> m;
    m <<= 1; // 修正位操作错误
    ll num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        weight[i] = num << 1;
    }
    auto bigger = [](int a, int b) -> bool {
        return a > b;
    };
    sort(weight, weight + n, bigger);

    for (int i = n - 1; i >= 0; i--)
    {
        // cout<< weight[i]<<" ";
        Sum[i] = Sum[i + 1] + weight[i];
        //cout << Sum[i] << " ";
    }

    dfs(0, 0, 0);

    if (ans == 50)
        cout << "-1" << endl;
    else
        cout << ans;

    return 0;
}
