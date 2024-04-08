#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map> //用于判断游戏是否可以结束
#include <map>
#include <stack>
using namespace std;
unordered_map<char, int> mp;
map<stack<char>, int> sa;
string as, bs;
queue<char> a, b;
stack<char> st;
int Time = 0;
bool Put(queue<char> &q)
{
    char f = q.front();
    st.push(f);
    q.pop();
    if (!mp.count(f))
    {
        mp[f] = st.size();
    }
    else
    {
        int len = st.size() - mp[f] + 1;
        mp.erase(f);
        for (int i = 0; i < len; i++)
        {
            char g = st.top();
            q.push(g);
            mp.erase(g);

            //将桌面上的牌拿出来的时候记得将作的标记清除
            
            //cout<<g<<" ";
            st.pop();
        }
        //cout<<endl;
        return Put(q);
    }
    return true;
}

// bool check(){

// }

void solve()
{
    while (!a.empty() && !b.empty()&&Time<100000)
    {
        Put(a);
        Put(b);
        Time ++ ;

    }
    if(Time>=100000){
        cout<<-1<<endl;
        return ;
    }
    if (!a.empty())
    {
        while (!a.empty())
        {
            char ac = a.front();
            cout << ac;
            a.pop();
        }
    }
    else if (!b.empty())
    {
        while (!b.empty())
        {
            char bc = b.front();
            cout << bc;
            b.pop();
        }
    }
}
int main()
{
    cin >> as >> bs;
    for (auto s : as)
    {
        a.push(s);
    }
    for (auto s : bs)
    {
        b.push(s);
    }
    solve();
    return 0;
}