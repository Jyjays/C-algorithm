#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510 , M = 100010;

int h[N],e[M],ne[M],idx =0 ;
int match[N];
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a] , h[a] ++ ;
}

int n,m,k;
bool find(int x){
    for(int i = h[x];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]) {
            st[j] = true;
            if(match[j]==0||find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>n>>m>>k;
    memset(h,-1,sizeof h);

    while(k--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }


    int res = 0;
    for(int i = 1; i <= n ;i ++)
    {  
         //因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
        memset(st,false,sizeof st);
        if(find(i)) 
          res++;
    }  

    cout<<res<<endl;
    return 0;
}