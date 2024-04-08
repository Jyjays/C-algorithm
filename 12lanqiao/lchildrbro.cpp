#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
#define int long long

using namespace std;
typedef pair<int ,int> pii;
const int N = 100010;
vector<pii> tree;
vector<int> child[N];
// unordered_map<int,int> st;
// unordered_map<int,int> len;
int n;
// 二分
int res = 0;
void dfs(int dep ,int u,int count){
    cout<<dep<<" "<<u<<" "<<count<<endl;
    if(count == n){  // count是已经加入树的节点数量
        res = max(res,dep);
        return ;
    }
    int length = child[u].size();
    for(int i=0;i<length;i++){ //找到u的所有子节点
        
        dfs(dep+length,child[u][i],count+length); //将该节点放在末尾
    }
}
signed main()
{
    cin >> n;
    int par;
    for(int i=2;i<=n;i++){
        cin>>par;
        tree.push_back({par,i});
        child[par] .push_back(i);
    }
    dfs(1,1,1);
    cout<<res;
    return 0;
}