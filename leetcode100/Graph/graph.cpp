#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution
{
public:
    int xs, xy;
    int ans;
    vector<vector<bool>> flags; // Optimize : 可以直接将grid的值改为0，避免使用flags数组
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if ((x < 0 || y < 0) || (x >= xy || y >= xs) || grid[x][y] == '0' || flags[x][y])
            return;
        flags[x][y] = true;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        ans = 0;
        xy = grid.size();
        xs = grid[0].size();
        flags = vector<vector<bool>>(xy, (vector<bool>(xs, false)));
        for (int i = 0; i < xy; i++)
        {
            for (int j = 0; j < xs; j++)
            {
                if (!flags[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q; // Store the rotted orange at the same time.
        int sy = grid.size();
        int sx = grid[0].size();
        bool all_zero = true;
        for (int i = 0; i < sy; i++)
        {
            for (int j = 0; j < sx; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    grid[i][j] = 3;
                    all_zero = false;
                }
                else if (grid[i][j] == 1)
                    all_zero = false;
            }
        }
        if (all_zero) return 0;
        auto check = [sy, sx, &grid](pair<int, int> node) -> bool
        {
            int x = node.second;
            int y = node.first;
            return y >= 0 && y < sy && x >= 0 && x < sx && grid[y][x] == 1;
        };
        int res = -1;
        pair<int, int> cur_node;
        while (!q.empty())
        {
            res++;
            int cur_size = q.size();
            for (int i = 0; i < cur_size; i++)
            {
                cur_node = q.front();
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    auto node = make_pair<int, int>(cur_node.first + dx[d], cur_node.second + dy[d]);
                    if (check(node))
                    {
                        q.push(node);
                        grid[node.first][node.second] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < sy; i++)
        {
            for (int j = 0; j < sx; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution s;
    int ans = s.orangesRotting(grid);
    cout << ans << endl;
    return 0;
}