#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
const int N = 100010;
unordered_map<int,vector<int>> nodes;
vector<int> max_block;
unordered_map<int,bool> isRoot;
int ans = N;
int n;
int root;
int dfs(int root){
    int sum =1,res =0;
    if(!nodes.count(root)){
        return 1;
    }
    int len = nodes[root].size();
    for(int i=0;i<len;i++){
        int s = dfs(nodes[root][i]);
        res = max(res,s);
        sum += s;
    }
    res = max(res,n-sum);
    ans = min(ans,res);

    return sum;
}

int main()
{

    cin>>n;
    for(int i =0;i<n;i++){
        int p,c;
        isRoot[c] = false;
        cin>>p>>c;
        nodes[p].push_back(c);
    }
    int len = isRoot.size();
    for(int i=1;i<=len+1;i++){
        if(!isRoot.count(i)){
            root = i;
            break;
        }
    }
    dfs(root);
    cout<<ans;
    return 0;
}