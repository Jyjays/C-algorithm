#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> pii;

int n;
int res = 0;
void chose_sec(vector<pii> &sec,vector<pii> &sec2)
{
    
    int ed = -2e9;
    for (auto &s : sec)
    {
        if (s.first > ed)
        {
            ed = s.second;
        }else{
            sec2.push_back(s);
        }
    }
    sec = sec2;
    sec2.clear();

}
vector<pii> sec;
vector<pii> sec2;

signed main()
{
    cin >> n;
    vector<pii> sec;
    vector<pii> sec2;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        sec.push_back({l, r});
    }
    auto cmp = [](pii a, pii b)
    {
        return a.second < b.second;
    };
    sort(sec.begin(), sec.end(), cmp);
    while(!sec.empty()){
        res++;
        chose_sec(sec,sec2);
    }
    cout<<res<<endl;
    return 0;
}