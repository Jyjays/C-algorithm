#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isNum(int n,int m){
    int res=0;
    int tmp = n;
    for(int i=0;i<m;i++){
        res+=tmp%10;
        tmp/=10;
    }
    int res2=0;
    for(int i=0;i<m;i++){
        res2+=tmp%10;
        tmp/=10;
    }
    if (res==res2) return true;
    else return false;
}

int numcount(int n){
    int top = 10;
    for(int i=n;i>1;i--){
        top*=10;
       // cout<<top<<endl;
    }
    int count =0;
    for(int i=top/10;i<top;i++){
        if(isNum(i,n/2)){
            count++;
        }
    }
    return count ;
}

int main(){
    cout<<numcount(2);
    int res = 9 + 615 + 50412 + 4379055;
    cout<<endl<<res;
    return 0;
}