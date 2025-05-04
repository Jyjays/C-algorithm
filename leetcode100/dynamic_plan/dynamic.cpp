#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

int climbStairs(int n) {
  vector<int> step(46);
  step[0] = 0;
  step[1] = 1;
  step[2] = 2;
  for (int i = 3; i < n; i++) {
    step[i] = step[i - 1] + step[i - 2];
  }
  return step[n];
}

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ret(numRows);
  for (int i = 0; i < numRows; ++i) {
    ret[i].resize(i + 1);
    ret[i][0] = ret[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
    }
  }
  return ret;
}

int rob(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return nums[0];
  if (n == 2) return max(nums[0], nums[1]);
  vector<int> max_steal(n, 0);
  max_steal[0] = nums[0];
  max_steal[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n; i++) {
    max_steal[i] = max(max_steal[i - 1], max_steal[i - 2] + nums[i]);
  }
  return max_steal[n - 1];
}

int numSquares(int n) {
  if (n <= 4) {
    return n;
  }
  vector<int> cnt(n + 1, n);
  cnt[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      int sq = j * j;
      if (sq > i) break;
      cnt[i] = min(cnt[i], cnt[i - sq] + 1);
    }
  }
  return cnt[n];
}

int coinChange(vector<int>& coins, int amount) {
  vector<int> cnt(amount + 1, amount);
  cnt[0] = 0;
  for (int i = 1; i <= amount; i++) {
    for (int j = 0; j < coins.size(); j++) {
      if (coins[j] > i) continue;
      cnt[i] = min(cnt[i], cnt[i - coins[j]] + 1);
    }
  }
  return cnt[amount];
}
bool wordBreak(string s, vector<string>& wordDict) {
  int len = s.size();
  int word_count = wordDict.size();
  vector<bool> m(len + 1, false);
  m[0] = true;
  for (int i = 1; i <= len; i++) {
    for (int j = 0; j < word_count; j++) {
      int l = wordDict[j].size();
      if (l > i) continue;
      m[i] = m[i] || (m[i - l] && s.substr(i - l, l) == wordDict[j]);
    }
  }
  return m[len];
}

int lengthOfLIS(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < n; j++) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}

int maxProduct(vector<int>& nums) {
  int n = nums.size();
  long maxF = nums[0], minF = nums[0], ans = nums[0];
  for (int i = 1; i < n; i++) {
    long mx = maxF, mn = minF;
    maxF = max(mx * nums[i], max(mn * nums[i], (long)nums[i]));
    minF = min(mn * nums[i], min(mx * nums[i], (long)nums[i]));
    ans = max(maxF, ans);
  }
  return ans;
}

bool canPartition(vector<int>& nums) {
  int n = nums.size();
  if (n < 2) return false;
  int sum = accumulate(nums.begin(), nums.end(), 0);
  int maxNum = *max_element(nums.begin(), nums.end());
  if (sum & 1) {
    return false;
  }
  int half = sum / 2;
  if (maxNum > half) {
    return false;
  }

  vector<vector<int>> dp(n, vector<int>(half + 1, 0));
  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  dp[0][nums[0]] = true;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= half; j++) {
      if (j >= nums[i]) {
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n - 1][half];
}
int longestValidParentheses(string s) {
    int n = s.size();
    int res = 0;
    vector<int> cnt(n, 0);
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') {
                cnt[i] = (i >= 2 ? cnt[i - 2] : 0 ) + 2;
 
            } else if (i - cnt[i - 1] > 0 && s[i - cnt[i - 1] - 1] == '(') {
                int start = (i - cnt[i - 1] >= 2) ? i - cnt[i-1] -2 : 0; 
                cnt[i] = cnt[start] + cnt[i-1] + 2;
            }
            res = max(res, cnt[i]);
        }
    }
    return res;
}

int uniquePaths(int m, int n) {
  vector<vector<int>> map(m, vector<int>(n, 1));
  // for (int i = 0; i < m; i++) {
  //   map[i][0] = 1;
  // }
  // for (int i = 0; i < n; i++) {
  //   map[0][i] = 1;
  // }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      map[i][j] = map[i-1][j] + map[i][j-1];
    }
  }
  return map[m-1][n-1];    
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 1; i < n; i++) {
      grid[0][i] += grid[0][i-1];
    }
    for (int i = 1; i < m; i++) {
      grid[i][0] += grid[i-1][0];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
      }
    }
    return grid[m-1][n-1];   
}

string longestPalindrome(string s) {
  int n = s.size();
  int maxLen = 0;
  int maxL,maxR;
  vector<vector<bool>> map(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    map[i][i] = true;
    for (int j = 0; j < i; j++) {
      if (s[i] == s[j] && (map[j + 1][i - 1] || i - j < 2)) {
        map[j][i] = true;
        if (i - j + 1 > maxLen) {
          maxLen = i - j + 1;
          maxL = j;
          maxR = i;
        }
      }
    }
  }
  return s.substr(maxL, maxLen);
}

int longestCommonSubsequence(string text1, string text2) {
  int l1 = text1.size(), l2 = text2.size();
  vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <= l2; j++) {
      if (text1[i-1] == text2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[l1][l2];
}

int minDistance(string word1, string word2) {
  int l1 = word1.size(), l2 = word2.size();
  //dp[i][j]表示将word1的前i个字母和word2的前j个字母编辑成相同字符串的编辑距离
  vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
  for (int i = 0; i <= l1; i++) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= l2; i++) {
    dp[0][i] = i;
  }  
  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <=l2; j++) {
      if (word1[i-1] == word2[j-1]) {
        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i-1][j], dp[i-1][j-1] - 1));
      } else {
        dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i-1][j], dp[i-1][j-1]));
      }
    }
  }
  return dp[l1][l2];
}


int main() {
  string s = "()((())";
  longestValidParentheses(s);
  return 0;
}