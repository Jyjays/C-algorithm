#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> vec = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 四个方向

int bfs(string start)
{
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    q.push(start); // 初始化队列和map
    d[start] = 0;
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        int dis = d[s];
        if (s == end)
        {
            return dis; // 得到最终结果
        }
        int site = s.find('x');
        int x = site / 3, y = site % 3; // 将一维下标转换成二维坐标

        for (int i = 0; i < 4; i++)
        {
            int a = x + vec[i].first;
            int b = y + vec[i].second;
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(s[site], s[a * 3 + b]); // a*3+b 坐标反向转换
                if (!d.count(s))
                {
                    d[s] = dis + 1;
                    q.push(s); // 保存当前状态
                }
                swap(s[site], s[a * 3 + b]); // 回调状态，以便下一次循环
            }
        }
    }
    return -1; // 如果没有结果就返回-1
}

int main()
{
    string start;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}