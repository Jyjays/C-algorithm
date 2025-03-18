
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int len = s.size();
  if (len < 2) {
    return len;
  }
  int maxLen = 1;
  unordered_map<char, int> m;
  int l = 0, r = 1;
  m[s[l]] = 1;
  while (r < len) {
    if (m[s[r]] == 0) {
      // 增大窗口，值是一个新的值
      m[s[r++]]++;
      maxLen = max(maxLen,r- l);
    } else {
      m[s[l++]]--;
    //   m[s[r]]++;
    //   r++;
    }
  }

  return maxLen;
}

int main() {
  string s;
  cin >> s;
  cout << lengthOfLongestSubstring(s);
  return 0;
}