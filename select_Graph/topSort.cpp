#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N =100010;
int h[N],e[N*2],ne[N*2];
int n,m,idx;
int rd[N];
queue<int> q;
vector<int > res;
void add(int a , int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}
//所有入度为零的点都可以排在前面，保证拓扑序列的正确性
bool bfs(){
    if(q.empty()) return false;
    while(!q.empty()){
        int j = q.front();
        //cout<< j<<" ";
        res.push_back(j);
        q.pop();
        for(int i=h[j];i!=-1;i=ne[i]) //枚举j的所有出边
        {
            int data = e[i];
            rd[data]--;
            if(rd[data]==0) {
                q.push(data);
            }
        }            
    }
    if(res.size()!=n) return false;
    return true;
}


int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    memset(rd,0,sizeof rd);
    
    for(int i=0;i<m;i++){
        int a, b;
        cin>> a>> b;
        add(a,b);
        rd[b]++;
    }
    for(int i=1;i<=n;i++){
        if(rd[i]==0) q.push(i); //先将所有入度为零的点入队
    }
    if(!bfs()){
        cout<<"-1";
    }else{
        for(auto i:res){
            cout<<i<<" ";
        }
    }
    return 0;
}