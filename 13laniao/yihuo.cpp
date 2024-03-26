#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define int long long 
using namespace std;
const int N = 100010;
typedef pair<int,int> pii;
int Xor(int x,int y){

    return x&~y|~x&y;
}
int a[N];
int sum[N];
int n,m,x;
vector<pii> query;

bool find(int l,int r){
    for(int i = l;i<=r;i++){
        for(int j = i+1;j<=r;j++){
            if(Xor(a[i],a[j])==x) 
                return true;
        }
    }
    return false;
}
signed main(){
    cin>>n>>m>>x;
    int l,r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        //query.push_back({l,r});
        if(find(l,r)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}