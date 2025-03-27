#include <stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 10010;
int h[N];
int size;
bool cmp(int a, int b) {
    return a > b;
}



vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();
    for (int i = 0; i < len;i++) {
        h[i + 1] = nums[i];
    }

}

int main() {
    int n,k;
    vector<int> nums(n);
    scanf ("%d %d",&n, &k);
    for (int i = 1; i<=n; i++) {
        scanf ("%d", &nums[i]);
    }
    auto res = maxSlidingWindow(nums,k);
    for (auto i: res) {
        printf("%d",i);
    }
    return 0;
}