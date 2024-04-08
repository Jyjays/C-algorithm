#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 +10;

int n,m,idx=0;

int h[N],e[N*2],ne[N*2],step[N];
bool st[N];
void add(int a,int b){
    e[idx] = b; ne[idx] = h[a]; h[a] =idx++;
}

int bfs(int u){
    queue<int> q;   
    st[u] = true;
    q.push(u);
    
    while(!q.empty()){
        int j = q.front();
        if(j == n){
            return step[j]; // 返回到达目标节点的步数
        }
        q.pop();
        for(int i=h[j];i!=-1;i=ne[i]){
            int data = e[i];             //将当前节点的所有邻接节点加入队列
            if(!st[data]){
                st[data] = true;
                step[data] = step[j] + 1; // 更新步数
                q.push(data);
            }
        }
    }
    return -1; // 无法到达目标节点
}

int main (){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    int start,end;
    for(int i=0;i<m;i++){
        cin>>start>>end;
        add(start,end); // 添加边
    }
    int ans = bfs(1); // 从节点1开始进行BFS
    cout<<ans<<endl;
    return 0;
}