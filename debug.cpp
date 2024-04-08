#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long 
#define INTM 0x3f3f3f3f
using namespace std;

const int N = 10010;
const int M = 100010;

int h[N],e[M],ne[M],w[M],limit[M],idx=0;
int dist[N];
bool st[N];
vector<pair<int,int> > l;
int n,m;
void add(int a,int b,int wi,int li){
    e[idx] =b,ne[idx] = h[a],w[idx] = wi,limit[idx] = li,h[a] = idx++;
    if(li){
        l.push_back({idx-1,idx});
    }
    e[idx] =a,ne[idx] = h[b],w[idx] = wi,limit[idx] = li,h[b] = idx++;
}

int spfa(){
    memset(dist,INTM,sizeof dist);
    memset(st,false,sizeof st);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        st[p] = false;
        // if(p == n){
        //    // cout<<"cut"<<endl;
        //     return dist[p];
        // }  
        //error:第一次到达n点时不一定是最小值
        for(int i = h[p];i!=-1;i=ne[i]){
            int data = e[i];
           // cout<<data<<":"<<limit[i]<<endl;;
            if(!limit[i] && dist[data] > dist[p]+w[i]){
                
                dist[data] = dist[p]+w[i];
                if(!st[data]){
                    q.push(data);
                    st[data] = true;
                    //cout<<data<<" "; 
                }
            }
        }
    }
    //cout<<endl;
    return dist[n] == INTM ? -1:dist[n];

}

signed main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    int a,b,wi,li;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wi>>li;
        add(a,b,wi,li);
        //add(b,a,wi,li);
    }
    int yres = spfa();
    int len = l.size();
    int mres = INTM;
    for(int i=0;i<len;i++)
    {

        limit[l[i].first]=0;
        limit[l[i].second] =0;
        int j=i+1;
        while(j<len){
            limit[l[j].first] = 0;
            limit[l[j].second] =0;
            mres = min(mres,spfa());
            limit[l[j].first] = 1;
            limit[l[j].second] = 1;
            j++;
        }
        limit[l[i].first] = 1;
        limit[l[i].second] = 1;
    }

    cout<<yres<<endl;
    cout<<yres - mres;
    return 0;
}



