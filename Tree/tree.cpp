#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* r = invertTree(root->left);
    TreeNode* l = invertTree(root->right);
    root->left = l;
    root->right = r;
    return root;
  }
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    queue<TreeNode*> children;
    children.push(root);
    children.push(root);
    TreeNode *n1, *n2;
    while (!children.empty()) {
      n1 = children.front();
      children.pop();
      n2 = children.front();
      children.pop();
      if (!n1 && !n2)
        continue;
      else if (!n1 || !n2 || n1->val != n2->val)
        return false;
      children.push(n1->left);
      children.push(n2->right);
      children.push(n1->right);
      children.push(n2->left);
    }
    return true;
  }
  bool check(TreeNode* left, TreeNode* right) {
    if (!left && !right)
      return true;
    else if (!left || !right || left->val != right->val)
      return false;
    return check(left->left, right->right) && check(left->right, right->left);
  }
  // 以某一个节点为中心节点计算的直径
  int max_diameter = 0;
  int diameterDFS(TreeNode* r) {
    if (r == nullptr) return 0;
    int ld = diameterDFS(r->left);
    int lr = diameterDFS(r->right);
    max_diameter = max(max_diameter, ld + lr + 1);
    return max(ld, lr) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    max_diameter = 1;
    diameterDFS(root);
    return max_diameter - 1;  // 不减一是经过的节点个数，减一是边的个数
  }
  // 层次遍历
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* n;
    while (!q.empty()) {
      int len = q.size();
      vector<int> level(len, 0);
      for (int i = 0; i < len; i++) {
        n = q.front();
        q.pop();
        level[i] = n->val;
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      res.push_back(level);
    }
    return res;
  }
  // 平衡二叉树
  TreeNode* helper(const vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
#define MAX INT_MAX
#define MIN INT_MIN
  int max_count = 0, min_count = 0;
  bool isValid(TreeNode* root, long long lb, long long rb) {
    if (root == nullptr) return true;

    if (root->val == MAX) {
      max_count++;
      if (max_count > 1) return false;
    } else if (root->val == MIN) {
      min_count++;
      if (min_count > 1) return false;
    }

    // Check bounds using long long comparison
    if (root->val >= rb || root->val <= lb) {
      return false;
    }

    return isValid(root->left, lb, (long long)root->val) &&
           isValid(root->right, (long long)root->val, rb);
  }
  bool isValidBST(TreeNode* root) {
    return isValid(root, (long long)MIN - 1, (long long)MAX + 1);
  }
  vector<int> nums;
  int K;
  void findkth(TreeNode* root) {
    if (root == nullptr) return;
    findkth(root->left);
    nums.push_back(root->val);
    if (nums.size() == K) return;
    findkth(root->right);
  }
  int kthSmallest(TreeNode* root, int k) {
    K = k;
    findkth(root);
    return nums.back();
  }
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;
    while (!q.empty()) {
      int len = q.size();
      while (len > 1) {
        len--;
        node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      node = q.front();
      res.push_back(node->val);
      q.pop();
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    return res;
  }
  TreeNode* r = new TreeNode();
  TreeNode* cur = r;
  void flattenHelper(TreeNode* root) {
    if (root == nullptr) return;
    cur->right = new TreeNode(root->val);
    cur = cur->right;
    flattenHelper(root->left);
    flattenHelper(root->right);
  }
  void flatten(TreeNode* root) {
    if (root == nullptr) return;
    flattenHelper(root);
    cur = r->right->right;
    TreeNode* rcur = root;
    while (cur) {
      rcur->right = cur;
      rcur->left = nullptr;
      rcur = rcur->right;
      cur = cur->right;
    }
  }
  TreeNode* buildTreeRetravel(unordered_map<int, int>& m, vector<int>& preorder,
                              vector<int>& inorder, int p_start, int p_end,
                              int i_start, int i_end) {
    if (p_start > p_end) return nullptr;
    TreeNode* root = new TreeNode(preorder[p_start]);
    int inorder_index = m[preorder[p_start]];
    int left_size = inorder_index - i_start;
    root->left =
        buildTreeRetravel(m, preorder, inorder, p_start + 1,
                          p_start + left_size, i_start, inorder_index - 1);
    root->right =
        buildTreeRetravel(m, preorder, inorder, p_start + left_size + 1, p_end,
                          inorder_index + 1, i_end);
    return root;
  }
  // 根据前序遍历和中序遍历建树
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> m;
    int len = inorder.size();
    for (int i = 0; i < len; i++) {
      m[inorder[i]] = i;
    }
    return buildTreeRetravel(m, preorder, inorder, 0, len - 1, 0, len - 1);
  }
  TreeNode* buildTree_dfs(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> s;
    s.push(root);
    int index = 0;
    for (int i = 1; i < preorder.size(); i++) {
      TreeNode* node = s.top();
      if (inorder[index] == node->val) {
        while (!s.empty() && inorder[index] == s.top()->val) {
          node = s.top();
          s.pop();
          index++;
        }
        node->right = new TreeNode(preorder[i]);
        s.push(node->right);
      } else {
        node->left = new TreeNode(preorder[i]);
        s.push(node->left);
      }
    }
    return root;
  }

  // 计算路径和等于目标值的路径个数
  int rootSum(TreeNode* root, long targetSum) {
    if (!root) {
      return 0;
    }
    int ret = 0;
    if (root->val == targetSum) {
      ret++;
    }
    ret += rootSum(root->left, targetSum - root->val);
    ret += rootSum(root->right, targetSum - root->val);
    return ret;
  }

  int pathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return 0;
    }

    int ret = rootSum(root, targetSum);
    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
  }

  std::pair<int,int> getLevel(TreeNode* root, TreeNode* p, TreeNode* q) {
    int level = 0;
    int l1,l2;
    queue<TreeNode*> qu;
    if (!root) return {0,0};
    qu.push(root);
    TreeNode* node;
    while (!qu.empty()) {
      int len = qu.size();
      level ++;
      while(len--) {
        node = qu.front();
        qu.pop();
        if (node == p) l1 = level;
        if (node == q) l2 = level;
        if (node->left) qu.push(node->left);
        if (node->right) qu.push(node->right);
      }
    }
    return {l1,l2};
  }
  // 祖先map
  unordered_map<TreeNode*, TreeNode*> parent_map;
  unordered_map<TreeNode*, bool> visited;
  void dfs(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left) {
      parent_map[root->left] = root;
      dfs(root->left);
    }
    if (root->right) {
      parent_map[root->right] = root;
      dfs(root->right);
    }
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    parent_map[root] = nullptr;
    dfs(root);
    while (p != nullptr) {
      visited[p] = true;
      p = parent_map[p];
    }
    while(q != nullptr) {
      if (visited[q]) return q;
      q = parent_map[q];
    }
    return nullptr;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);
  Solution s;
  s.flatten(root);
  int res = s.pathSum(root, 3);
}