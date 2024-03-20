
#include<stdio.h>

#include<algorithm>
using namespace std;

const int N  = 100010;
int n,m;
int a[N],sum[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    int l,r;
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r] - sum[l-1]);
    }
    return 0;
}

