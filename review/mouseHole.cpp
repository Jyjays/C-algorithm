#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

#define dist(x1, y1, z1, x2, y2, z2) sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1),2))

using namespace std;
const int N = 1010;
unordered_map<int,int> m;
vector<int> bottom,top;
int p[N];
void init(int n){
    for(int i=0;i<=n+1;i++){
        p[i] =i ;
    }
}
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

struct node
{
    int x, y, z;
} nodes[N];

int t;

void link_1(int n,int r){
    if(nodes[n].z<=r){
       // m[find(n)]++;  
        bottom.push_back(n);
        return;  
    }
}
void link_2(int n,int r,int h,int all){
    if(h-nodes[n].z<=r){
        //m[find(n)]++;
        top.push_back(n);
        return;     
    }
    
}
void link(int n1,int n2,int r){
    int d =dist(nodes[n1].x,nodes[n1].y,nodes[n1].z,nodes[n2].x,nodes[n2].y,nodes[n2].z);
    //cout<<"dist:"<<d<<endl;
    if(d<=2*r){
        int p1 = find(n1),p2 = find(n2);
        p[p2] = p1;
    }
}
bool check(){
    for(auto &i:bottom){
        for(auto &j:top){
            if(find(i)==find(j)){
                return true;
            }
        }
    }
    return false;
}
bool cnt(int n,int h,int r){
    for(int i=1;i<=n;i++){
        link_1(i,r);
        link_2(i,r,h,n);
        for(int j=i;j<=n;j++){
            link(i,j,r);
        }
    }
    return check();
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    int n, h, r;

    for (int k = 0; k < t; k++)
    {
        memset(nodes,0,sizeof nodes);
        memset(p,0,sizeof p);
        cin >> n >> h >> r;
        init(n);
        int x, y, z;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y >> z;
            nodes[i] = {x, y, z};
        }
        if(cnt(n,h,r))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main()
{
    
    solve();
    return 0;
}