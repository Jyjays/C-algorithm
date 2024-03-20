#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;

int cnt[N];
int n;
int res =0;
int main(){
    cin>>n;
    int str[N];
    for(int i=0;i<n;i++){
        cin >> str[i];
    }

    /*
        i,j 双指针代表的区间是目前能找到的最大的不重复子序列区间
        所以在ij之间已经不存在重复序列，可能的只是在扩充序列时加进来的字符
        同时，随着i向右移动，j也只能向右移动，这是重复序列的单调性
    */
    for(int i=0,j=0;i<n;i++){
        cnt[str[i]] ++ ;
        while(cnt[str[i]]>1){
            cnt[str[j]]--;
            j++;
        }
        res = max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}