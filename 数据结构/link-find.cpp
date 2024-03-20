#include<iostream>
#include<string>
using namespace std;

const int N = 100010;

int p[N];
int cnt[N];
int n,m;

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i] = i;
        cnt[p[i]] = 1 ;
    } 
    string f;
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>f;
        if(f=="C"){
            cin>>a>>b;
            if(find(a)!=find(b)){
                cnt[find(b)] += cnt[find(a)];  //准备将a集合合并到b集合上
                p[find(a)] = find(b);
            }
            
        }
        if(f=="Q1"){
            cin>>a>>b;
            if(find(a)==find(b)){
                cout<<"Yes"<<endl;
            }else {
                cout<<"No"<<endl;
            }
        }
        if(f == "Q2"){
            cin>>a;
            cout<<cnt[p[find(a)]]<<endl;
        }
    }
    return 0;
}