#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> res;
  int len = nums.size();
  if (len < 3) {
    return res;
  }
  if (len == 3) {
    if (nums[0] + nums[1] + nums[2] == 0) {
      res.push_back(nums);
    }
    return res;
  }
  sort(nums.begin(), nums.end());

  for (int i = 0; i < len; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int t = len -1;
    int target = -nums[i];
    for (int j= i+1;j<len;j++) {
        if (j > i +1 && nums[j] == nums[j-1]) {
            continue;
        }
        while (j < t && nums[j] + nums[t] > target) {
            t -- ;
        }
        if (j == t) {
            break;
        }
        if (nums[j] + nums[t] == target) {
            res.push_back({nums[i],nums[j],nums[t]});
        }
    }
  }
  return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    nums.resize(n);
    for (int i = 0;i<n;i++) {
        cin >> nums[i];
    }
    auto res = threeSum(nums);
    int colSize = res.size();
    for (int i = 0;i< colSize;i ++) {
        int len = res[i].size();
        for (int j = 0;j < len;j ++) {
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}