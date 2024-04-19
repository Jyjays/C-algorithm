#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> pii;
const int N = 100010;
vector<pii> sec;
map<pii,int> m;
bool st[N];
int T,n,t,d,l;
bool flag = false;
void dfs(int time,int cnt,int all){
    if(cnt == all ){
        flag = true;
        return;
    }
    for(int i =0;i<all;i++){
        if(!st[i]&&sec[i].second>=time){
            st[i] = true;
            dfs(max(time,sec[i].first) + m[sec[i]],cnt+1,all); //如果来的晚就要等一会
            st[i] = false;
        }
    }
}
void solve(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin >> n;
        sec.clear();
        memset(st,false,sizeof st);
        m.clear();
        for(int i=0;i<n;i++){
            cin>>t>>d>>l;
            sec.push_back({t,t+d});
            m[{t,t+d}] = l;
        }
        flag = false;
        dfs(0,0,n);
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}