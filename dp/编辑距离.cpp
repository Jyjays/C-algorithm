#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010;

int n,m;
int op;
string a[N],b;

int main(){
    cin>>n>>m;
    for(int i = 1 ;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=m;i++){
        int f[N][N];
        
        cin >>b>>op;
        int count=0;

        
        if(a[i] == b){
            count ++;
        }
        int len = a[i].length();
        int len2 = b.length();

        for(int i =0;i<=len;i++) f[i][0] = i;
        for(int i =0;i<=len2;i++) f[0][i] = i;
        for(int j =1;j<=len;j++){
            for(int k =1;k<=len2;k++){
                f[j][k] = min(f[j-1][k],f[j][k-1])+1;
                if(a[i][j]==b[k]) f[j][k] = min(f[j][k],f[j-1][k-1]);
                else f[j][k] = min(f[j][k],f[j-1][k-1]+1);
            }
        }
        if(f[len][len2] <= op){
            count++;
        }
        cout<<count<<endl;
    }

    return 0;


}