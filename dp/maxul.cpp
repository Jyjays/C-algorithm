#include <iostream>
#include <algorithm>
//#define int long long
using namespace std;

const int N = 100010;
const int E = 1e9;
int n, k, res;
int a[N];
int f[N][N]; // 前N个数中K个数相乘的最大值

void solve() {
    for (int i = 1; i <= n; i++) {
        f[i][1] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= i && j <= k; j++) { // 这里改为从2开始，因为f[i][1]已经初始化过了
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] * a[i]);
        }
    }
    res = 0 - ((0-f[n][k])%E+9);
    cout<<res<<endl;
    //cout << res;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve();
    return 0;
}
