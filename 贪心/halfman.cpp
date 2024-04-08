#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
//#define int long long 
using namespace std;

int n ;
vector<int> a;

int main(){
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    //使用小根堆
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        q.push(num);
    }
    
    int res = 0;
    while(q.size()>1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        res += a+b;
        q.push(a+b);
    }
    cout<<res<<endl;
    return 0;
}



// int main(){
//     cin>>n;
//     int num;
//     for(int i=0;i<n;i++){
//         cin>>num;
//         a.push_back(num);
//     }
//     sort(a.begin(),a.end());
//     int res = 0;
//     for(int i=0;i<n-1;i++){
//         a[i+1] = a[i] + a[i+1];
//         res += a[i+1];
//         sort(a.begin()+i+1,a.end());
//     }
//     cout<<res<<endl;
//     return 0;
// }
