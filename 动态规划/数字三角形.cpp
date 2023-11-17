#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;

int num[N][N];
int f[N][N];
int n;

//列一下数字三角形的坐标不难得出行与行之间坐标的关系
//用递归的方法将大三角形化成若干个小三角形 
int getMax(int x, int y) {
    if (x == n) return num[x][y];
    return max(num[x][y] + getMax(x + 1, y), num[x][y] + getMax(x + 1, y + 1));
}

int main() {
	cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for(int i=1;i<=n;i++) f[n][i] = num[n][i];
    for(int i=n-1;i>0;i--){
    	for(int j=1;j<=i;j++){
    		f[i][j] = max(f[i+1][j]+num[i][j],f[i+1][j+1]+num[i][j]);
		}
	} 

    //int res = getMax(1, 1);
    cout << f[1][1];
    return 0;
}

