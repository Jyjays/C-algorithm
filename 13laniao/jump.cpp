#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N = 100010;
const int INTM = 0x3f3f3f3f;
int n,x;
int cnt ;
int stone[N];

int mins = 1;

void jump(){
    int tmp[N] ;
    memcpy(tmp,stone,sizeof stone);
    for(int i=1;i<=cnt;i++){
        int locate = 0;
        int st = mins;
        while(locate < n){
            if(locate+mins>=n) break;
            if(tmp[st+locate]){
                locate +=st;
                tmp[st+locate] --;
            }else{
                int st_tmp = st;
                while(!tmp[st_tmp+locate]){
                    st_tmp--;
                    if(st_tmp==0){
                        mins ++;
                        //cout<<mins<<" ";
                        i= 1;
                        memcpy(tmp,stone,sizeof stone);
                    }
                }
                locate +=st_tmp;
                tmp[st_tmp+locate] -- ; 
            }
        }
    }
}

int main(){
    cin>>n>>x;
    cnt = x*2;
    for(int i=1;i<n;i++){
        cin>>stone[i];
    }
    jump();
    cout<<mins;
    return 0;
}