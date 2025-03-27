#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    string res;
    unordered_map<char, int> m; // t的map
    unordered_map<char, int> m2;// 滑动窗口的map
    int len = s.size();
    int kl = t.size();
    for (int i = 0; i < kl; i++) {
        m[t[i]] ++;
    }
    auto check = [&m,&m2] () {
        for (const auto &iter : m) {
            if (m2[iter.first] < iter.second) {
                return false;
            }
        }
        return true;
    };
    int l = 0, r = -1;
    int maxlen = INT_MAX, ansL = -1;
    while (r < len) {
        if (auto iter = m.find(s[++r]); iter != m.end()) {
            m2[iter->first] ++;
        } 
        while (check() && l <= r) {
            if (r - l + 1 < maxlen) {
                maxlen = r - l + 1;
                ansL = l;
            }
            if (m.find(s[l]) != m.end()) {
                m2[s[l]]--;
            }
            l++;
        }
    }
    return ansL == -1 ? "" : s.substr(ansL, maxlen);
}

int main(){
    string s, t;
    cin >> s >> t;
    string res = minWindow(s,t);
    cout << res;
    return 0;
}
