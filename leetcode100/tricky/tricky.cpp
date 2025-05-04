#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
   int res = 0;
   int n = nums.size();
   for (int i = 0; i < n; i++) {
    res ^= nums[i];
   }     
   return res;
}
int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int res = 0;
    for (auto i : nums) {
        if (cnt == 0) {
            res = i;
        } 
        if (i == res){
            cnt++;
        } else {
            cnt--;
        }
    }
    return res;
}
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int p0 = 0, p2 = n-1;
    for (int i = 0; i <= p2; i++) {
        while (nums[i] == 2 && i <= p2) {
            swap(nums[i], nums[p2]);
            p2--;
        }
        if (nums[i] == 0) {
            swap(nums[i], nums[p0]);
            p0++;
        }
    }
    
}

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >=0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    // i之后的都是降序排列，所以，找到的第一个大于nums[i]的数就是最小的
    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int findDuplicate(vector<int>& nums) {
    int n = nums.size(), res = 0;
    int bit_max = 31;
    while (!((n - 1) >> bit_max)){
        bit_max--;
    }          
    for (int bit = 0; bit <= bit_max ;bit++) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & (1 << bit)){
                x += 1;
            }
            if (i > 1 && (i & (1 << bit))) {
                y += 1;
            }
        }
        if (x > y) {
            res |= 1 << bit;
        }
    }
    return res;
}

int main() {

}