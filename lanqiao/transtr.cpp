#include<iostream>
#include<cstring>

#include<algorithm>
using namespace std;

int ans =0;
bool isBigger(string str1,string str2){
    int len1 = str1.size();
    int len2 = str2.size(); 
    if(len1!=len2) return len1>len2;
    for(int i =0;i<len1;i++){
        if(str1[i]==str2[i]) continue;
        else return str1[i]-'0' > str2[i]-'0';
    }
    return false;
}

void bfs(string str,int begin ,int end){
    string tmp = str;
    reverse(tmp.begin()+begin,tmp.begin()+end+1);
    //cout<<tmp<<endl;
    if(str>tmp) {
        ans++;
        //cout<<begin<<" "<<end<<endl;
    }
}

int main(){
    string str;
    cin>>str;
    //str = "210102";
    int len = str.size();
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            bfs(str,i,j);
        }
    }
    //bfs(str,0,1);
    cout<<ans;
    return 0;
}