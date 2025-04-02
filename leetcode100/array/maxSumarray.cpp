#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// O(n2)
// int maxSubArray(vector<int>& nums) {
//   int res = INT_MIN;
//   int len = nums.size();
//   vector<int> a(len + 1);
//   for (int i = 1; i <= len; i++) {
//     a[i] = nums[i - 1] + a[i - 1];
//   }
//   for (int cur_len = 1; cur_len <= len; cur_len++) {
//     for (int i = cur_len; i <= len; i++) {
//       res = max(res, a[i] - a[i - cur_len]);
//     }
//   }
//   return res;
// }

// dp O(n)
int maxSubArray(vector<int>& nums) {
    int res = INT_MIN;
    int len = nums.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    for (int i = 1; i <= len; i++) {
        dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int res = maxSubArray(nums);
  cout << res;
  return 0;
}