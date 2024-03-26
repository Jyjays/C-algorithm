#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void getNext(const string &s, vector<int> &next)
{
    int j = 0;
    next[0] = 0;
    int len = s.size();
    for (int i = 2; i <= len; i++)
    {
        while (j > 0 && s[j+1] != s[i]) // 不相等，回退找到最大的相同前缀后缀或直到j=0
        {
            j = next[j];
        }
        if (s[j + 1] == s[i])
        {
            j++;
        }

        next[i] = j;
    }
}

//找到所有匹配的位置
vector<int> kmp(const string &s1, const string &s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int> next(len1, 0);
   
    vector<int> res;
    getNext(s2, next);
    
    for(int i=1,j=0;i<=len1;i++){
        while (j > 0 && s1[i] != s2[j+1]) {
            j = next[j];
        }
        if(s1[i] == s2[j+1]){
            j++;
        }
        if(j == len2){
            res.push_back(i-j);
            j = next[j];
        }
    }
    
    return res;
}

int main()
{
    string s1,s2;
    int n,m;
    cin>>n;
    cin>>s1;

    cin>>m;
    cin>>s2;
    vector<int> res = kmp(s2,s1) ;
    if(res.size() > 0){
        for(auto i : res){
            cout<<i<<endl;
        }
    }else{
        cout<<"-1"<<endl;
    }

    return 0;
}
/*
// STL find 函数
int main(){
    string s1 = "abaababac";
    string s2 = "abab";
    int idx = s1.find(s2);
    while(idx != string::npos){
        cout<<idx<<endl;
        idx = s1.find(s2, idx+1);
    }
    return 0;
}

*/