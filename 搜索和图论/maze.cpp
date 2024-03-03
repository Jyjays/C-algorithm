#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> // 包含了 INT_MAX
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> maze,path;
vector<pair<int, int>> step = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}};



void forward(int i, int &x, int &y)
{
    x += step[i].first;
    y += step[i].second;
}

int min_path = INT_MAX;

void getPath(int x, int y, int count)
{
    //printf("site is (%d,%d)\n", x, y);

    if (x == n - 1 && y == m - 1) // 修正终点坐标
    {
        min_path = min(min_path, count);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tmp_x = x + step[i].first; // 直接计算下一个位置的坐标
        int tmp_y = y + step[i].second;
        if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < m && maze[tmp_x][tmp_y] == 0) // 添加边界检查
        {
            maze[tmp_x][tmp_y] = 1;
            getPath(tmp_x, tmp_y, count + 1);
            maze[tmp_x][tmp_y] = 0;
        }
    }
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i =0;i<4;i++){
            int tmp_x = x + step[i].first; // 直接计算下一个位置的坐标
            int tmp_y = y + step[i].second;
            if (tmp_x >= 0 && tmp_x < n && tmp_y >= 0 && tmp_y < m && maze[tmp_x][tmp_y] == 0) // 添加边界检查
            {
                path[tmp_x][tmp_y] = path[x][y] + 1; // 修正步数
                maze[tmp_x][tmp_y] = 1;
                q.push({tmp_x,tmp_y});
            }
        }
    }

}

int main()
{
    cin >> n >> m;
    maze.resize(n, vector<int>(m, 0));
    path.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) // 修正输入数据范围
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    
    //getPath(0, 0, 0); // 修改起点坐标和起始步数
    // if (min_path == INT_MAX) // 如果没有找到可行路径，输出-1
    //     cout << "-1" << endl;
    // else
    //     cout << min_path << endl;
    bfs();
    cout<<path[n-1][m-1]<<endl;
    return 0;
}
