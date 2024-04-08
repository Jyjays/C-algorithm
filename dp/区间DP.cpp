#include<iostream>
#include<algorithm>
using namespace std;

const int N = 310;

int n;
int s[N];//前缀和
int f[N][N];//f[i][j]表示前i个数分成j段的最大值

int main(){
    cin>>n;
    for(int i =1;i<=n;i++) cin>>s[i], s[i] +=s[i-1];
    for(int len = 2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j = len+i-1;
            f[i][j] = 0x3ffffff;
            for(int k = i ; k<j;k++){
                f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);

            }
        }
    } 
    cout<<f[1][n]<<endl;
    return 0;
}