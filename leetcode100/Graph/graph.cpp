#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int N = 1000;

int xs, xy;
int ans;
vector<vector<bool>>
    flags;  // Optimize : 可以直接将grid的值改为0，避免使用flags数组
void dfs(vector<vector<char>>& grid, int x, int y) {
  if ((x < 0 || y < 0) || (x >= xy || y >= xs) || grid[x][y] == '0' ||
      flags[x][y])
    return;
  flags[x][y] = true;
  dfs(grid, x + 1, y);
  dfs(grid, x - 1, y);
  dfs(grid, x, y + 1);
  dfs(grid, x, y - 1);
}
int numIslands(vector<vector<char>>& grid) {
  ans = 0;
  xy = grid.size();
  xs = grid[0].size();
  flags = vector<vector<bool>>(xy, (vector<bool>(xs, false)));
  for (int i = 0; i < xy; i++) {
    for (int j = 0; j < xs; j++) {
      if (!flags[i][j] && grid[i][j] == '1') {
        dfs(grid, i, j);
        ans++;
      }
    }
  }

  return ans;
}

vector<vector<int>> edges;  // 先修 -> 后修
vector<int> indegree;
// 拓扑排序解决有向图的环问题
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  edges.resize(numCourses);
  indegree.resize(numCourses, 0);
  for (auto& edge : prerequisites) {
    edges[edge[1]].push_back(edge[0]);
    indegree[edge[0]]++;
  }
  queue<int> q;
  for (int i = 0; i < numCourses; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  int count = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    count++;
    for (auto& next : edges[cur]) {
      indegree[next]--;
      if (indegree[next] == 0) {
        q.push(next);
      }
    }
  }
  return count == numCourses;
}

int orangesRotting(vector<vector<int>>& grid) {
  queue<pair<int, int>> q;  // Store the rotted orange at the same time.
  int sy = grid.size();
  int sx = grid[0].size();
  bool all_zero = true;
  for (int i = 0; i < sy; i++) {
    for (int j = 0; j < sx; j++) {
      if (grid[i][j] == 2) {
        q.push({i, j});
        grid[i][j] = 3;
        all_zero = false;
      } else if (grid[i][j] == 1)
        all_zero = false;
    }
  }
  if (all_zero) return 0;
  auto check = [sy, sx, &grid](pair<int, int> node) -> bool {
    int x = node.second;
    int y = node.first;
    return y >= 0 && y < sy && x >= 0 && x < sx && grid[y][x] == 1;
  };
  int res = -1;
  pair<int, int> cur_node;
  while (!q.empty()) {
    res++;
    int cur_size = q.size();
    for (int i = 0; i < cur_size; i++) {
      cur_node = q.front();
      q.pop();
      for (int d = 0; d < 4; d++) {
        auto node = make_pair<int, int>(cur_node.first + dx[d],
                                        cur_node.second + dy[d]);
        if (check(node)) {
          q.push(node);
          grid[node.first][node.second] = 3;
        }
      }
    }
  }
  for (int i = 0; i < sy; i++) {
    for (int j = 0; j < sx; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }
  return res;
}

class Trie {
 private:
  struct TrieNode {
    bool isEnd_; // 判断是否是单词的结尾
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd_(false) {}
    TrieNode(bool end) : isEnd_(end) {}
    bool isEnd() { return isEnd_; }
    void setEnd(bool isend) { isEnd_ = isend; }
  };
  TrieNode* root;

 public:
  Trie() {
    root = new TrieNode();
    root->setEnd(true);
  }

  void insert(string word) {
    TrieNode* cur = root;
    for (char c : word) {
      if (cur->children.find(c) == cur->children.end()) {
        cur->children[c] = new TrieNode();
      }
      cur = cur->children[c];
    }
    cur->setEnd(true);
  }

  bool search(string word) {
    TrieNode* cur = root;
    for (char c : word) {
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c];
    }
    return cur->isEnd();
  }

  bool startsWith(string prefix) {
    TrieNode* cur = root;
    for (char c : prefix) {
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c];
    }
    return true;
  }
};

vector<vector<int>> permute_res;
unordered_map<int,bool> permute_map;
vector<int> permute_nums;
int permute_size = 0;
void permute_dfs(vector<int>& res, int level) {
  if (level == permute_size) {
    permute_res.push_back(res);
    //int last = res.back();
    //res.pop_back();
    // permute_map[last] = false;
    return;
  }
  for (int i: permute_nums) {
    if (!permute_map[i]){
      permute_map[i] = true;
      res.push_back(i);
      permute_dfs(res,level + 1);
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

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  return 0;
}