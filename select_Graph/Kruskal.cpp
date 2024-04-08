#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 200010;
int n,m;
int p[N];

struct Edge{
    int a,b,w;
    bool operator < (const Edge& e) const{
         return w < e.w;
    }
}edges[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int res =0,cnt = 0;
void kruskal(){
    for(int i=0;i<m;i++){
        int a = edges[i].a,b=edges[i].b,w = edges[i].w;
        int pa = find(a),pb = find(b);
        if(pa!=pb){ //如果两个点不在同一个集合中
            p[pa] = pb; //合并两个集合
            res+=w;
            cnt++;
        }
    }
    //cout<<res<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = {a,b,w};
    }   
    auto cmp = [](Edge a,Edge b){
        return a.w < b.w;
    };
    sort(edges,edges+m,cmp);
    for(int i=1;i<=n;i++) p[i] = i; //初始化并查集
    kruskal();
    if(cnt<n-1) cout<<"impossible"<<endl;
    else cout<<res<<endl;
    return 0;
}