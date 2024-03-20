#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

const int N = 100010;
int n;
ll num[N];
ll res = 0;
ll bitXor(ll x, ll y) {
    return ~(~(~x&y)&~(x&~y));
}
void sum(){
    for(int len=1;len<n;len++){
        
        for(int i=1;i+len<=n;i++){
            ll tmp = 0;
            for(int j = i;j<=len+i;j++){
                tmp = bitXor(tmp,num[j]);
            }
            res+=tmp;
            tmp = 0;
        } 
        
    }
    
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sum();
    cout<<res<<endl;
    return 0;
}