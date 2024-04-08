#include<iostream>
#include<algorithm>

#define int long long 
using namespace std;

int n;
int a,b,c;
int res = n;
void solve(){
    int mn = 2*min(a,min(b,c));
    res -= mn;
    for(int i = mn+1;i<=n;i++){
        if(i%a||i%b||i%c){
            res--;
        }
    }

}
signed main(){
    cin >> n;
    cin>>a>>b>>c;
    cout<<res<<endl;
    return 0;
}