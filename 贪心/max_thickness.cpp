#include<iostream>
#include<algorithm>

#define int long long

using namespace std;

const int N = 100010;

int n,idx=0;
int sec[N];
//vector<pair<int,int>> sec;
signed main(){
    cin>>n;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        sec[idx++] = l*2;
        sec[idx++] = r*2+1;
        //这样处理的原因有两点
        //1.可以区分左端点和右端点
        //2.端点有交点算是相交的，那么右端点会出现的比左端点tor更晚
        /*
            sec.push_back({l*2,1});
            sec.push_back({r*2+1,-1});
        */
    }
    sort(sec,sec+idx);
    int res = 1,thick = 0;
    for(int i =0;i<idx;i++){
        //当前区间是左端点，厚度加一，否则减一
        if(sec[i]%2 == 0){
            thick ++;
        }else{
            thick --;
        }
        res = max(res,thick);
    }
    cout<<res<<endl;
    return 0;
}
