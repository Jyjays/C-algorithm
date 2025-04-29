#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> permute_res;
unordered_map<int, bool> permute_map;
vector<int> permute_nums;
int permute_size = 0;
void permute_dfs(vector<int>& res, int level) {
  if (level == permute_size) {
    permute_res.push_back(res);
    // int last = res.back();
    // res.pop_back();
    //  permute_map[last] = false;
    return;
  }
  for (int i : permute_nums) {
    if (!permute_map[i]) {
      permute_map[i] = true;
      res.push_back(i);
      permute_dfs(res, level + 1);
      permute_map[i] = false;
      res.pop_back();
    }
  }
}

// 全排列
vector<vector<int>> permute(vector<int>& nums) {
  permute_nums = nums;
  permute_size = nums.size();
  for (auto i : nums) {
    permute_map[i] = false;
  }
  vector<int> res;
  permute_dfs(res, 0);
  return permute_res;
}
vector<vector<int>> subsets_res;
vector<int> sub_nums;
int sub_size = 0;
void subsetsbfs(vector<int>& res, int cur) {
  if (cur == sub_size) {
    subsets_res.push_back(res);
    return;
  }
  res.push_back(sub_nums[cur]);
  subsetsbfs(res, cur + 1);
  res.pop_back();
  subsetsbfs(res, cur + 1);
}
vector<vector<int>> subsets(vector<int>& nums) {
  sub_nums = nums;
  sub_size = nums.size();
  vector<int> res;
  subsetsbfs(res, 0);
  return subsets_res;
}

unordered_map<int, vector<char>> phone_map;
vector<string> phone_ans;
string phone_res;
string phone_digits;
void phone_dfs(int cur) {
  if (cur == phone_digits.size()) {
    phone_ans.push_back(phone_res);
    return;
  }
  const vector<char>& vec =
      phone_map[phone_digits[cur] - '0'];  // 注意：用 digits[cur] 映射到数字
  for (char c : vec) {
    phone_res.push_back(c);  // 添加当前字符
    phone_dfs(cur + 1);      // 递归下一位
    phone_res.pop_back();    // 回溯撤销添加
  }
}

vector<string> letterCombinations(string digits) {
  if (digits.size() == 0) {
    return vector<string>();
  }
  char a = 'a';

  for (int i = 2; i <= 9; i++) {
    vector<char> cs = {a, static_cast<char>(a + 1), static_cast<char>(a + 2)};
    a += 3;
    if (i == 7 || i == 9) {
      cs.push_back(a);
      a++;
    }
    phone_map[i] = cs;
  }
  phone_digits = digits;
  phone_dfs(0);
  return phone_ans;
}

vector<int> conbination_candidates;
vector<vector<int>> conbination_ans;
vector<int> conbination_res;
int conbination_target;
int c_size;

void conbination_dfs(int start, int sum) {
  if (sum == conbination_target) {
    conbination_ans.push_back(conbination_res);
    return;
  }

  if (sum > conbination_target) {
    return;
  }

  for (int i = start; i < conbination_candidates.size(); i++) {
    conbination_res.push_back(conbination_candidates[i]);
    // 因为可以重复选择同一个数字，所以还是从 i 开始
    conbination_dfs(i, sum + conbination_candidates[i]);
    conbination_res.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  conbination_target = target;
  conbination_candidates = candidates;
  c_size = candidates.size();
  conbination_dfs(0, 0);
  return conbination_ans;
}

vector<string> parent_res;
string cur_res;
int par_n;
void Parenthesis(int left, int right) {
  if (right > left || left > par_n) {
    return;
  }
  if (right == par_n) {
    parent_res.push_back(cur_res);
    return;
  }

  if (left > right) {
    cur_res.push_back('(');
    Parenthesis(left + 1, right);
    cur_res.pop_back();

    cur_res.push_back(')');
    Parenthesis(left, right + 1);
    cur_res.pop_back();
  } else {
    cur_res.push_back('(');
    Parenthesis(left + 1, right);
    cur_res.pop_back();
  }
}
vector<string> generateParenthesis(int n) {
  par_n = n;
  Parenthesis(0, 0);
  return parent_res;
}
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
bool exist_flag = false;
string exist_word;
int bx, by;
vector<vector<char>> Board;

struct tuple_hash {
  template <typename T1, typename T2>
  std::size_t operator()(const std::tuple<T1, T2>& t) const {
    return std::hash<T1>()(std::get<0>(t)) ^ std::hash<T2>()(std::get<1>(t));
  }
};

unordered_map<tuple<int, int>, bool, tuple_hash> tmap;
void exist_dfs(int to_find, int x, int y) {
  if (exist_flag || x < 0 || y < 0 || x >= bx || y >= by || tmap[{x, y}])
    return;

  char cur_char = Board[y][x];
  if (cur_char != exist_word[to_find]) return;  // 关键修正：字符不匹配立即终止

  if (to_find == exist_word.size() - 1) {
    exist_flag = true;
    return;
  }

  tmap[{x, y}] = true;
  for (int i = 0; i < 4; ++i) {
    int newx = x + dx[i], newy = y + dy[i];
    exist_dfs(to_find + 1, newx, newy);
    if (exist_flag) break;  // 提前终止
  }
  tmap[{x, y}] = false;
}
bool exist(vector<vector<char>>& board, string word) {
  exist_flag = false;  // 状态重置
  tmap.clear();
  Board = board;
  exist_word = word;
  by = board.size();
  if (by == 0) return false;
  bx = board[0].size();

  for (int i = 0; i < by; ++i) {
    for (int j = 0; j < bx; ++j) {
      if (board[i][j] == word[0]) {
        exist_dfs(0, j, i);
        if (exist_flag) return true;  // 找到即返回
      }
    }
  }
  return false;
}
vector<vector<string>> partition_ans;
vector<string> p_res;
string ori_s;
bool check(string s) {
  for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
    if (s[i] != s[j]) return false;
  }
  return true;
}
void partition_dfs(int cur) {
  if (!p_res.empty() && !check(p_res.back())) {
    return;
  }
  if (cur == ori_s.size()) {
    partition_ans.push_back(p_res);
    return;
  }
  for (int length = 1; length + cur <= ori_s.size(); length++) {
    p_res.push_back(ori_s.substr(cur, length));
    partition_dfs(cur + length);
    p_res.pop_back();
  }
}
vector<vector<string>> partition(string s) {
  ori_s = s;
  partition_dfs(0);
  return partition_ans;
}

vector<vector<bool>> map;
vector<vector<string>> queens;

int qn;
bool haveConflict(int row, int col) {
    for (int i = 0; i < row; i++) {
        int k1 = col - row + i; // 位置左侧斜线上的位置
        int k2 = col + row - i; // 右侧斜线
        if (map[i][col] || (k1 >= 0 && map[i][k1]) || (k2 < qn && map[i][k2])) {
            return true;
        }
    }
    return false;
}

void nqueen(int row, int remainQueens) {
    if (remainQueens == 0) {
        vector<string> res;
        for (int i = 0; i < qn; i++) {
            string s = "";
            for (int j = 0; j < qn; j++) {
                char c = map[i][j] ? 'Q' : '.';
                s.push_back(c);
            }
            res.push_back(s);
        }
        queens.push_back(res);
        return;
    }
    if (row >= qn) return;

    for (int i = 0; i < qn; i++) {
        if (!haveConflict(row, i)) {
            map[row][i] = true;
            nqueen(row + 1, remainQueens -1);
            map[row][i] = false;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    map.resize(n, vector<bool>(n, false));
    qn = n;
    nqueen(0, n);
    return queens;
}

int main() {
  // vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  // string dighits = "223";
  // auto res = letterCombinations(dighits);

  //   vector<int> candidates = {2, 3, 5, 7};
  //   combinationSum(candidates, 7);
  //   string word = "BAA";
  //   vector<vector<char>> board = {{'B'},{'A'},{'B'}, {'B'},{'A'}};
  //   exist(board, word);
  string s = "a";
  auto ans = partition(s);

  solveNQueens(1);
  return 0;
}