#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 100010;

int h[N],e[N],ne[N],w[N],idx=0;
bool st[N];
int dist[N];

void add(int a,int b,int c){
    e[idx]= b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

void spfa(){
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    q.push(1);
    st[1] = true;
    dist[1] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int d = e[i];
            if(dist[t]+w[i]<dist[d]){
                dist[d] = dist[t] + w[i];
                if(!st[d]){
                    q.push(d);
                    st[d] = true;
                }

            }
        }
    }
}
int n,m;
int main(){
    cin>>n>>m;
    int l,r,v;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        cin>>l>>r>>v;
        add(l,r,v);
        add(r,l,v);
    }
    spfa();
    cout<<dist[3];
    return 0;
}