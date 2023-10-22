#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int y, n, m;
    cin >> y >> n >> m;

    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    //sort(B.begin(), B.end()); // 对集合B的元素进行排序

    vector<int> dp(y + 1, y + 1);
    dp[0] = 0;

    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            } else {
                break; // 提前终止循环
            }
        }
        for (int j = 0; j < m; j++) {
            if (i % B[j] == 0) {
                dp[i] = min(dp[i], dp[i / B[j]] + 1);
            } else if (B[j] > i) {
                break; // 提前终止循环
            }
        }
    }

   
    cout << dp[y] << endl;
    

    return 0;
}

