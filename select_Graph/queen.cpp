#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> map;
int boardSize;

void printMap(vector<vector<bool>> &map) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (map[i][j]) {
                cout << "Q";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool hasConflict(int x, int y) {
    for (int i = 0; i < x; i++) {
        if (map[i][y] || (y - x + i >= 0 && map[i][y - x + i]) || (y + x - i < boardSize && map[i][y + x - i])) {
            return true;
        }
    }
    return false;
}

void dfs(int remainingQueens, int row) {
    if (remainingQueens == 0) {
        printMap(map);
        return;
    }
    if (row >= boardSize) {
        return;
    }
    for (int i = 0; i < boardSize; i++) {
        if (!hasConflict(row, i)) {
            map[row][i] = true;
            dfs(remainingQueens - 1, row + 1);
            map[row][i] = false;
        }
    }
}

int main() {
    boardSize = 4;
    map.resize(boardSize, vector<bool>(boardSize, false)); // 初始化棋盘状态为全false
    dfs(boardSize, 0);
    return 0;
}
