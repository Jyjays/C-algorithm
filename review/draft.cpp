#include<bits/stdc++.h>
//#define int long long 
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N = 100;
int dist[N];
int n,m;
int d[N][N];
bool st[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
    
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

int h[N],e[N],ne[N],w[N],idx=0;
void add(int a,int b,int v){
    e[idx]=b,ne[idx] = h[a],w[idx] = v,h[a] = idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    st[1] = true;
    while(!q.empty()){
        auto [u,v] = q.top();
        q.pop();
        if(st[v]){
            continue;
        }
        st[v] = true;
        for(int i = h[v];i!=-1;i=ne[i]){
            int data = e[i];
            if(dist[data]> dist[v]+w[data]){
                dist[data] = dist[v] + w[data];
                q.push({dist[data],data});
            }
           
        }
    }
    return dist[n] == 0x3f3f3f3f? -1: dist[n];
}

void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
}
void init(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        /*
          输入边
          cin>>a>>b>>v;
          d[a][b] = min(d[a][b],v);
          add(a,b,v);
            add(b,a,v);
        */
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    return 0;

}