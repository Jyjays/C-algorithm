#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int N = 100010;
int n, k;
int a[N], q[N];
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> qu;
    vector<int> res;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (!qu.empty() && qu.front() < i - k + 1) {
            qu.pop_front();
        }
        while (!qu.empty() && nums[qu.back()] >= nums[i]) {
            qu.pop_back();
        }
        qu.push_back(i);
        if (i >= k - 1) res.push_back(nums[qu.front()]);
    }
    return res;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int hh = 0, tt = -1;  // 队头和队尾
  for (int i = 0; i < n; i++) {
    if (hh <= tt && q[hh] < i - k + 1) hh++;    // 队列向前移动
    while (hh <= tt && a[q[tt]] >= a[i]) tt--;  // 将不单调的值出队
    q[++tt] = i;
    if (i >= k - 1) printf("%d ", a[q[hh]]);  // 队头元素就是最小值
  }
  puts("");
  hh = 0;
  tt = -1;
  for (int i = 0; i < n; i++) {
    if (hh <= tt && q[hh] < i - k + 1) hh++;
    while (hh <= tt && a[q[tt]] <= a[i]) tt--;
    q[++tt] = i;
    if (i >= k - 1) printf("%d ", a[q[hh]]);
  }
  return 0;
}

