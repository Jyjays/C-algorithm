#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

char a[N],b[N];

int f[N][N];   // 将a的前i个字符改成b的前j个字符的最少操作次数

int n,m;

//将第一个字符串改成第二个字符串有三种操作：删除，插入，替换
int main(){
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1);

    for(int i =0;i<=m;i++) f[0][i] = i ; //将a的前0个字符改成b的前i个字符的最少操作次数，即插入i次
    for(int i =0;i<=n;i++) f[i][0] = i ; //将a的前i个字符改成b的前0个字符的最少操作次数

    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=m;j++){
            f[i][j] = min(f[i-1][j],f[i][j-1])+1;     //删除或插入
            if(a[i]==b[j]) f[i][j] = min(f[i][j],f[i-1][j-1]);
            else f[i][j] = min(f[i][j],f[i-1][j-1]+1);  //替换
        }
    }
    printf("%d\n",f[n][m]); 
    return 0;
}
