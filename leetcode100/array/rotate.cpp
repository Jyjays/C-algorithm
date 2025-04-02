#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// void trans(vector<int>& nums, int tmp, int cur_i, int next_i, int count, int k) {
//   if (count == nums.size()) return;
//   int cur_tmp = nums[next_i];
//   nums[next_i] = tmp;
//   //nums[next_i] = nums[cur_i];
//   trans(nums, cur_tmp, next_i, (next_i + k) % nums.size(), ++count, k);
// }

// void rotate(vector<int>& nums, int k) {
//   int len = nums.size();
//   int offset = k %len;
//   int tmp = nums[offset];
//   nums[offset] = nums[0];
//   trans(nums, tmp, offset, (offset + k) % len, 1, k);
// }

// void rotate(vector<int>& nums, int k) {
//     int len = nums.size();
//     vector<int> tmp(len);
//     for (int i = 0; i< len; i++) {
//         tmp[(i + k) % len] = nums[i];
//     }
//     nums = tmp;
//   }
void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start += 1;
        end -= 1;
    }
}

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  rotate(nums, k);
  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  return 0;
}
