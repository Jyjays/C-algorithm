#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N =14;
int f[N]; // 表示从n位开始连对10个的情况
int sum[N] ; //从1到n的情况之和

void dp(){
    f[1] = 1;
    f[2] = 1;
    sum[2] = 2;
    for(int i=3;i<=13;i++){
        f[i] = pow(2,i-1) - sum[i-1];
        sum[i] = sum[i-1] + f[i];
    }
}
int ans =0;
void bfs(int count,int sum){
    if(sum==100||count>=31){
        return ;
    }
    if(sum==70){
        ans++;
    }
    bfs(count+1,sum+10);
    bfs(count+1,0);
}
int main(){
    bfs(0,0);
    cout<<ans;
    return 0;
}