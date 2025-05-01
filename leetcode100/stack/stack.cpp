#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  bool flag = true;
  if (s.size() == 1) return false;
  for (auto c : s) {
    if (c == '(' || c == '{' || c == '[') {
      st.push(c);
    } else {
      if (st.empty()) return false;
      char tp = st.top();
      st.pop();
      if ((c == ')' && tp != '(') || (c == '}' && tp != '{') ||
          (c == ']' && tp != '[')) {
        flag = false;
        break;
      }
    }
  }
  return flag && st.empty();
}

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    st.push(val);
    if (min_st.empty() || val <= min_st.top()) {
      min_st.push(val);
    }
  }

  void pop() {
    int tp = st.top();
    st.pop();
    if (!min_st.empty() && tp == min_st.top()) {
      min_st.pop();
    }
  }

  int top() { return st.top(); }

  int getMin() { return min_st.top(); }

 private:
  stack<int> st;
  stack<int> min_st;
};

int ptr;
string src;

int getdigits() {
  int count = 0;
  while (ptr < src.size() && isdigit(src[ptr])) {
    count += count * 10 + src[ptr++] - '0';
  }
  return count;
}
string decodeStringdfs() {
  if (ptr == src.size() || src[ptr] == ']') {
    return "";
  }
  string res;
  if (isdigit(src[ptr])) {
    int count = getdigits();
    ptr++;
    string repeat = decodeStringdfs();
    ptr++;
    while (count--) res += repeat;
  } else if (isalpha(src[ptr])) {
    res = string(1, src[ptr++]);
  }
  return res + decodeStringdfs();
}
string decodeString(string s) {
  ptr = 0;
  src = s;
  return decodeStringdfs();
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
  stack<int> st;
  int n = temperatures.size();
  vector<int> res(n, 0);
  for (int i = 0; i < n; i++) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      res[st.top()] = i - st.top();
      st.pop();
    }
    st.push(i);
  }

  return res;
}
int largestRectangleArea(vector<int>& heights) {
    stack<int> single_st;
    int n = heights.size();
    vector<int> left(n); // i左侧距离最近的且高度小于i的点
    vector<int> right(n); // i右侧距离最近的且高度小于i的点
    for (int i = 0; i < n; i++) {
        while (!single_st.empty() && heights[single_st.top()] >= heights[i]) {
            single_st.pop();
        }
        left[i] = single_st.empty() ? -1 : single_st.top();
        single_st.push(i);
    }

    single_st = stack<int>();
    for(int i = n - 1; i >=0; i--) {
        while (!single_st.empty() && heights[single_st.top()] >= heights[i]) {
            single_st.pop();
        }
        right[i] = single_st.empty() ? n : single_st.top();
        single_st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max((right[i] - left[i] - 1) * heights[i],ans);
    }
    return ans;
}

int main() {
  string s = "3[a]2[bc]";
  string res = decodeString(s);
  return 0;
}