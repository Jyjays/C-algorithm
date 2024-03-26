#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

const int N = 1e6+10;

vector<int> s;
vector<pii> section;

int n;

int main(){
    cin>>n;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        section.push_back({l,r});
        s.push_back(l),s.push_back(r);
    }
    // int cnt = section.size();
    // vector<int>::iterator it = unique(s.begin(),s.end());
    // cnt = cnt - (it - s.end());
    // s.erase(it,s.end());
    auto cmp = [](pii p1,pii p2){
        return p1.first < p2.first;
    };
    sort(section.begin(),section.end(),cmp);
    //int len = section.size();
    int res = 1;
    int maxr = section[0].first;
    for(auto &it : section){
        if(maxr >= it.first)  maxr = max(maxr,it.second);
        else{
            maxr = it.second;
            res ++ ;
        }
    }
    cout<<res<<endl;
    return 0;
}

