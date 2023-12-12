#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 优化输入输出
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<double> o1;
    vector<double> o2;
    o1.reserve(n + 1);  
    o2.reserve(n + 1);

    o1.push_back(1);
    o2.push_back(0);

    int k; double op;
    for (int i = 0; i < n; i++) {
        cin >> k >> op;
        if (k == 1) {
            o1.push_back(o1.back() * op);
            o2.push_back(o2.back());
        } else if (k == 2) {
            o1.push_back(o1.back());
            o2.push_back(o2.back() + op);
        }
    }

    int l, r; double x, y;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> x >> y;
        double scaleFactor = o1[r] / o1[l - 1];
        double rotationAngle = o2[r] - o2[l - 1];
        double cosAngle = cos(rotationAngle), sinAngle = sin(rotationAngle);
        double x1 = x * scaleFactor, y1 = y * scaleFactor;
        double x2 = x1 * cosAngle - y1 * sinAngle;
        double y2 = x1 * sinAngle + y1 * cosAngle;
        cout << fixed << setprecision(3) << x2 << ' ' << y2 << '\n';
    }
    return 0;
}

