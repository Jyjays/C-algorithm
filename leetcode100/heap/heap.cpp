#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int> q;
  for (auto i : nums) {
    q.push(i);
  }
  int K = k;
  while (--k) {
    q.pop();
  }
  return q.top();
}
struct Compare {
  bool operator()(const pair<int, int> p1, const pair<int, int> p2) const {
    return p1.second < p2.second;  // 大根堆
  }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> m;
  for (auto i : nums) {
    m[i]++;
  }
  auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q(m.begin(),
                                                                    m.end());
  vector<int> res;
  while (k--) {
    res.push_back(q.top().first);
    q.pop();
  }
  return res;
}
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (qmin.empty() || num < qmin.top()) {
        qmin.push(num);
        if (qmin.size() > qmax.size() + 1) {
            qmax.push(qmin.top());
            qmin.pop();
        }
    } else {
        qmax.push(num);
        if (qmax.size() > qmin.size() + 1) {
            qmin.push(qmax.top());
            qmax.pop();
        }
    }
  }

  double findMedian() {
    if ((qmin.size() + qmax.size()) % 2 == 0) {
        return (double)(qmin.top() + qmax.top()) /2;
    }
    return qmin.size() > qmax.size() ? qmin.top() : qmax.top();
  }

 private:
  priority_queue<int, vector<int>, less<int>> qmin; // 中位数左侧的值
  priority_queue<int, vector<int>, greater<int>> qmax; // 中位数右侧的值
};

int main() { return 0; }