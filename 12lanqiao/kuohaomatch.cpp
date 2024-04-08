#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

set<string> res;
string str;

pair<int,int> isValid(const string& s) {
    int openCount = 0, closeCount = 0;
    for (char c : s) {
        if (c == '(') {
            openCount++;
        } else if (c == ')') {
            if (openCount > 0) {
                openCount--;
            } else {
                closeCount++;
            }
        }
    }
    return {openCount, closeCount};    
}

void dfs(string cur, int oc, int cc, int umo, int umc) {
    
    auto [o, c] = isValid(cur);
    if(oc>umc||cc>umo||o>umo||c>umc){
        return;
    }
    if ((!o && !c) && oc == umc && cc == umo) {
        res.insert(cur);
        return;
    } else {
        int len = cur.size();
        if (oc < umc) {
            for (int i = 0; i <= len; i++) {  
                string tmp = cur;
                tmp.insert(i,1,'(');
                dfs(tmp, oc + 1, cc, umo, umc); 
            }
        }
        if (cc < umo) {
            for (int i = 0; i <= len; i++) {  
                string tmp = cur;
                tmp.insert(i,1,')');
                dfs(tmp, oc, cc + 1, umo, umc); 
            }
        }
    }
}

void solve() {
    auto [o, c] = isValid(str);
    dfs(str, 0, 0, o, c); 
    cout << res.size();
}

int main() {
    cin >> str;
    solve();
    return 0;
}
