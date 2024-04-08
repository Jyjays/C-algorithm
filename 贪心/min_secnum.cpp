/*
问题描述：选择尽量少的区间，能覆盖掉给出的范围
*/
/*
解题思路：使用贪心算法，在保证覆盖区间的前提下，选择右端点最大的区间
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long 
using namespace std;
typedef pair<int,int> pii;
int l,r;
int n;
vector<pii> sec;

signed main(){
    cin>>l>>r;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        sec.push_back({x,y});
    }
    auto cmp = [](pii a,pii b){
        return a.first < b.first;
    };
    sort(sec.begin(),sec.end(),cmp);
    int res = 0;
    bool flag = false;
    //int st = -2e9,ed = -2e9;
    // for(auto &s:sec){
    //     if(!flag)  //初始化，先找到第一个区间
    //     {
    //         if(s.first <= l && s.second >= l){
    //             flag = true;
    //             st = s.first;
    //             ed = s.second;
    //         }else if(s.first > l) //如果第一个区间的左端点都比l大，那么无法覆盖
    //         {
    //             break;
    //         }
    //     }
    //     if(flag){
    //         if(s.first > ed) break;
    //         if(s.first <= ed && s.second > ed){
    //             res++;
    //             st = ed;
    //             ed = s.second;
    //         }
    //         if(ed >= r) break;
    //     }       
    // }
    for(int i = 0;i<n;i++){
        int j = i,lasted= -2e9;    //使用lasted不断更新要覆盖的起点
        while(j<n&&sec[j].first<=l){
            lasted = max(lasted,sec[j].second);
            j++;
        }
        if(lasted < l){             //lasted在循环内的原因
            break;
        }
        res++;
        if(lasted >= r){
            flag = true;
            break;
        }
        i = j-1;
        l = lasted;
    }
    if(flag){
        cout<<res<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}