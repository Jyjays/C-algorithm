#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int searchInsert(vector<int>& nums, int target) {
  int l = 0,
      r = nums.size();  // r = nums.size()，不会越界，而且能找到要插入的位置
  auto check = [](int a, int b) { return a < b; };
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (check(nums[mid], target)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  // if (nums[l] == target) {
  //     return l;
  // } else {
  //     return target > nums[l] ? l + 1 : l;
  // }
  return l;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int l = 0, r = matrix.size() - 1;
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (target <= matrix[l].back()) {
      break;
    } else if (matrix[mid].back() < target) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  int row = l;
  int flag = binary_search(matrix[row].begin(), matrix[row].end(), target);
  return flag;
}

vector<int> searchRange(vector<int>& nums, int target) {
//   int flag = binary_search(nums.begin(), nums.end(), target);
//   if (!flag) {
//     return {-1, -1};
//   }
  auto l = lower_bound(nums.begin(), nums.end(), target);
  auto r = upper_bound(nums.begin(), nums.end(), target);
  if (l == nums.end()) return {-1,-1};
  return {static_cast<int>(distance(nums.begin(), l)),
          static_cast<int>(distance(nums.begin(), r)) - 1};
}

int search(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 0) return -1;
    if (len ==1) return nums[0] == target ? 0 : -1;

    int l = 0, r = len -1;
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[0] <= nums[mid]) {
            // 左侧有序的情况
            if (nums[0] < target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            // 右侧有序
            if (nums[mid] < target && target <= nums[len -1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}
int findMin(vector<int>& nums) {
  int n = nums.size();
  if (!n) return -1;
  if (n == 1) return nums[0];
  int l = 0, r = n -1;
  // 不管怎么旋转，都只会是两个递增的子数组
  while (l < r) {
    int mid = (l + r) >> 1;
    if (nums[mid] < nums[r]) {
        r = mid;
    } else if (nums[mid] >= nums[r]) {
        l = mid + 1;
    }
  } 
  return nums[l];     
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int mid = (n1 + n2) >> 1;
    bool ji = (n1 + n2)%2;
    vector<int> nums(mid + 1);
    int l = 0, r = 0, i = 0;
    while (i < mid + 1 && l < n1 && r < n2) {
        if (nums1[l] < nums2[r]) nums[i++] = nums1[l++];
        else nums[i++] = nums2[r++];
    }
    while (i < mid +1 && l < n1) nums[i++] = nums1[l++];
    while (i < mid +1 && r < n2) nums[i++] = nums2[r++];
    if (ji) return (double)nums[mid - 1];
    return (double)(nums[mid] + nums[mid-1]) /2;
    
}

int main() {}