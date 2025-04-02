#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Not meet the request of O(n) size use;
// int firstMissingPositive(vector<int>& nums) {
//     int res = 1;
//     int len = nums.size();
//     std::unordered_map<int,bool> m;
//     for (int i = 0; i < len; i++) {
//         if (nums[i] > 0) {
//             m[nums[i]] = true;
//         }
//     }
//     while (m.find(res) != m.end()) {
//         res ++;
//     }
//     return res;
// }

int firstMissingPositive(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        while (nums[i] != i + 1) {
            // 将nums映射为nums[i] = i + 1
            // nums[i] == nums[nums[i] - 1]是为了检测重复值
            if (nums[i] <=0 || nums[i] >= len || nums[i] == nums[nums[i] - 1] ) {
                break;
            }
            int idx = nums[i] - 1;
            swap(nums[i],nums[idx]);
        }
    }
    for (int i = 0 ;i < len; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return len + 1;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << firstMissingPositive(nums);
  return 0;
}