#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;




// int trap(vector<int>& height) {
//     int len = height.size();
//     if (len < 2) return 0;

//     int total = 0;
//     for (int i = 0;i < len;i ++) {
//         int leftHeight = height[i];
//         int reduce = 0;

//         if (i + 1 < len && height[i + 1] >= leftHeight) {
//             continue;
//         }
//         // 属于同一个槽的条件为：height比leftHeight小
//         // 截至条件为：right height大于等于left right
//         bool isdown = true;
//         int tmp_add = 0;
//         for (int j = i + 1;j < len;j ++) {
            
//             if (height[j] >= leftHeight) {
//                 int add = min(leftHeight,height[j]) * (j - i -1) - reduce;
//                 total += add;
//                 i = j - 1;
//                 break;
//             }

//             if (!isdown && (j + 1 < len && height[j] > height[j + 1])||(j == len - 1)) {
//                 // 将该槽中的雨水加到total中
//                 int add = min(leftHeight,height[j]) * (j - i -1) - reduce;
//                 tmp_add = max(tmp_add,add);
//                 // i = j - 1;
//                 // break;
//             } else if (j + 1 < len && height[j] < height[j + 1]) {
//                 isdown = false;
//             }
//             if (j == len - 1) {
//                 total += tmp_add;
//                 i = j -1;
//                 break;
//             }

            
//             reduce += height[j];
//         }
//     }

//     return total;
// }

int trap(vector<int>& height) {
    int leftMax = 0;
    int rightMax = 0;
    int l = 0;
    int r = height.size() - 1;
    int total = 0;
    while (l < r) {
        leftMax = max(height[l], leftMax);
        rightMax = max(height[r],rightMax);
        if (leftMax < rightMax) {
            total += leftMax - height[l];
            l ++;
        } else {
            total += rightMax - height[r];
            r --;
        }
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    vector<int> height;
    height.resize(n);
    for (int i=0;i < n;i++) {
        cin >> height[i];
    }
    int res = trap(height);
    cout << res;
    return 0;
}