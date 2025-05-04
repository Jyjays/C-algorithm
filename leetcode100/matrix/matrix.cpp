#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  set<int> row, col;
  int m = matrix.size();
  int n = matrix[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        row.insert(i);
        col.insert(j);
      }
    }
  }
  for (auto r : row) {
    for (int i = 0; i < n; i++) {
      matrix[r][i] = 0;
    }
  }
  for (auto c : col) {
    for (int i = 0; i < m; i++) {
      matrix[i][c] = 0;
    }
  }
}

const pair<int, int> dd[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int m = matrix.size(), n = matrix[0].size();
  int y = 0, x = 0, dr = 0;
  vector<int> res;
  while (true) {
    res.push_back(matrix[y][x]);
    matrix[y][x] = 101;
    int ny, nx;
    int i = 4;
    while (i > 0) {
      ny = y + dd[dr].first;
      nx = x + dd[dr].second;
      if (ny >= m || ny < 0 || nx < 0 || nx >= n || matrix[ny][nx] == 101) {
        dr = (dr + 1) % 4;
        i--;
      } else {
        break;
      }
    }
    if (i == 0) break;
    y = ny, x = nx;
  }
  return res;
}

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  // 垂直翻转
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n; j++) {
        swap(matrix[i][j], matrix[n - i - 1][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j ++) {
        swap(matrix[i][j], matrix[j][i]);
    }
  }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int y = 0, x = m - 1;
    while (x >=0 && y < n) {
        if (matrix[y][x] == target) {
            return true;
        } else if (matrix[y][x] < target) {
            y++;
        } else {
            x--;
        }
    }
    return false;    
}
int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(matrix);
  for (auto i : matrix) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}