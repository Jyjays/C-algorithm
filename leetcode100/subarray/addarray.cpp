#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 前缀和
int subarraySum(vector<int>& nums, int k) {
  int res = 0;
  int len = nums.size();
  unordered_map<int, int> pre;
  pre[0] = 1; // 别忘了先添加一个前缀为0的情况
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum = sum + nums[i];
    if (pre.find(sum - k) != pre.end()) {
      res += pre[sum - k];
    }
    pre[sum]++;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << subarraySum(nums, k);
  return 0;
}