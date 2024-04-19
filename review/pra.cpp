#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<vector<int>> maxSlidingWindow2D(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));
    deque<int> row_max_index;

    for (int i = 0; i < m; ++i) {
        deque<int> col_max_index;
        for (int j = 0; j < n; ++j) {
            while (!col_max_index.empty() && matrix[i][j] >= matrix[i][col_max_index.back()]) {
                col_max_index.pop_back();
            }
            col_max_index.push_back(j);

            if (j - col_max_index.front() + 1 > k) {
                col_max_index.pop_front();
            }

            if (i >= k - 1) {
                result[i - k + 1][j - k + 1] = matrix[i][col_max_index.front()];
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 1, 2, 6},
        {7, 5, 4, 6, 3},
        {3, 2, 1, 2, 3},
        {8, 4, 2, 5, 7},
        {3, 2, 1, 3, 6}
    };
    int k = 3;
    vector<vector<int>> result = maxSlidingWindow2D(matrix, k);
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
