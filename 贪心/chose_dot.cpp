#include <iostream>
#include <algorithm>
#include <vector>
//#define int long long
using namespace std;

typedef pair<int, int> pii;

const int N = 100010;

int n;

vector<pii> sec;
int chose_dot()
{
    int res = 0;
    vector<int> dots;
    for (auto &s : sec)
    {
        if (!dots.empty() && s.first <= dots.back() && s.second >= dots.back())
        {
            //cout << "s.first: " << s.first << " s.second: " << s.second << endl;
            continue;
        }
        else
        {
            res++;
            dots.push_back(s.second);
        }
    }
    return res;
}
signed main()
{
    cin >> n;
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        sec.push_back({l, r});
    }
    auto cmp = [](pii a, pii b)
    {
        return a.second < b.second;
    };
    sort(sec.begin(), sec.end(), cmp);
    int res = chose_dot();
    cout << res << endl;
    return 0;
}
