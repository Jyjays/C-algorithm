#include<iostream>
#include<algorithm>
#include<vector>
#define int long long 
using namespace std;
typedef pair<int,int> pii;

const int N = 100010;

int n;
vector<pii> sec;
//问题描述：给定n个区间，选择尽量多的区间，使得这些区间两两不相交
int chose_sec(){
    auto cmp = [](pii a,pii b){
        return a.second < b.second;
    };
    sort(sec.begin(),sec.end(),cmp);
    int res =0;
    int ed = -2e9;
    for(auto &s:sec){
        if(s.first > ed){
            res++;
            ed = s.second;
        }
    }
    return res;
}
//另一种选择方式，按照区间的左端点排序，选择最小的右端点，减少对后续区间的影响
int chose_sec_2(){
    auto cmp = [](pii a,pii b){
        return a.first < b.first;
    };
    sort(sec.begin(),sec.end(),cmp);
    int res = 0;
    int ed = sec[0].second;
    for(auto &s:sec){
        if(s.second <= ed){
            ed = min(ed,s.second);
        }else{
            res++;
            ed = s.second;
        }
    }
    return res;
}
signed main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        sec.push_back({l,r});
    }
    
    int res = chose_sec_2();
    cout<<res<<endl;
    return 0;
}