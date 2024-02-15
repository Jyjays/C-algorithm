#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int maxl,maxr;

string longestPalindrome(string s) {
    int len = s.size();
    bool **f = new bool*[len];
    for(int i = 0; i < len; i++){
        f[i] = new bool[len];
        memset(f[i], 0, sizeof(bool) * len); // 初始化为false
    }
    
    int maxlen = 0;
    for(int i = 0; i < len; i++){
        f[i][i] = true; // 单个字符是回文串
        for(int j = 0; j < i; j++){
            if(s[i] == s[j] && (f[j+1][i-1] || i-j<2)){ // 状态转移方程
                f[j][i] = true;
                if(i-j+1 > maxlen){ // 更新最长回文串的长度
                    maxlen = i-j+1;
                    maxl = j;
                    maxr = i;
                }
            }
        }
    }
    
    for(int i = 0; i < len; i++){
        delete[] f[i];
    }
    delete[] f;
    return s.substr(maxl, maxr - maxl + 1);
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s);
    return 0;
}
