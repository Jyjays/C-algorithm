#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
using namespace std;
const int N = 100010;
string num[N];
int res = 0;

void dfs(int all,int last,int i,int cnt){
    if(i==all){
        if(num[last].back()==num[i][0]){
            cnt++;
        }
        res = max(res,cnt);
        return ;
    }
    char end = num[last].back();
    //cout<<end;
    char st = num[i][0];
    
    if(end==st||i==1){
        dfs(all,i,i+1,cnt+1);
    }
    dfs(all,last,i+1,cnt);
}
void solve(){
    int n;
    cin>>n;
    string str;
    //cin>>str;
   // istringstream iss(str);
    //while(iss>>num[n]);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    dfs(n,0,1,0);
    cout<<n-res<<endl;
}
int main(){
    solve();
    return 0;
}