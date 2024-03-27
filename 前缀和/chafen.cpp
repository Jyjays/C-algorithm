#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int a[N],b[N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i] - a[i-1];
    }
    int l,r,c;
    for(int i=0;i<m;i++){
        cin>>l>>r>>c;
        b[l] += c;
        b[r+1] -= c;
    }    
    for(int i=1;i<=n;i++){
        a[i] = a[i-1] + b[i];
        cout<<a[i]<<" ";
    }
    return 0;
}
