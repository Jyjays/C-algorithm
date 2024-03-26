#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;

int a[N],b[N];

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int j =0;
    for(int i=0;i<m;i++){
//        cout<<"now aj and bi is:"<<a[j]<<" "<<b[i]<<endl;
        if(a[j]==b[i]){
//            cout<<a[j]<<" "<<b[i]<<endl;
            j++;
//            cout<<j<<" ";
        }
    }
    if(j>n-1) printf("Yes\n");
    else printf("No\n");
    return 0;
}