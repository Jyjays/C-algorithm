#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int a[N],q[N];
//q是一个单调队列，存储的是a数组的下标
int n,k;
int main(){
    cin>>n>>k;
    int hh =0, tt = -1; // hh队头 tt队尾
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(hh <= tt && i - q[hh] >=k) hh++; // 队头元素是否已经超出窗口范围
        while(hh <= tt && a[q[tt]] >= a[i]) tt--; // 队尾元素是否大于当前元素，如果大于则出队，因为大的元素不可能是最小的
        q[++tt] = i;  // 入队
        if(i >= k-1) cout<<a[q[hh]]<<' '; // 输出队头元素,因为单调性，队头元素是最小的
        // i >= k-1 说明窗口已经形成
    }
    cout<<endl;
    hh = 0,tt = -1;
    //求最大值
    for(int i=0;i<n;i++){
        if(hh <= tt && i - q[hh] >=k) hh++; //与上面一样
        while(hh <= tt && a[q[tt]] <= a[i]) tt--; // 符号相反
        q[++tt] = i;
        if(i >= k-1) cout<<a[q[hh]]<<' ';
    }
    return 0;
}