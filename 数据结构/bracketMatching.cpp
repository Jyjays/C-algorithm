#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N  = 10010;

char str[N];

bool match(string str, stack<char>& stk){
    int len = str.size();
    for(int i=0;i<len;i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            stk.push(str[i]);
        }
        if(str[i]=='}'|| str[i]==')'||str[i]==']'){
            if(stk.empty()) return false;
            char t = stk.top();
            stk.pop();
            if(str[i]=='}' && t!='{') return false;
            if(str[i]==']' && t!='[') return false;
            if(str[i]==')' && t!='(') return false;
        
        }
    }
     if (stk.empty()) return true;
    else return false;
}
//更快的方法
 bool isValid(string s) {
        unordered_map<char,char>hashtable=
        {
            {')','('},
            {'}','{'},
            {']','['},
        };
        stack<char>stk;
        for(char ch:s)
        {
            if(hashtable.count(ch))
            {
                if(stk.empty()||stk.top()!=hashtable[ch])
                return false;
                else
                stk.pop();
            }
            else
            stk.push(ch);
        }
        return stk.empty();

    }
int main (){
    cin >> str;
    stack<char> stk;
    bool flag = match(str,stk);
    if(flag && stk.empty()) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}