#include<iostream>
#include<algorithm>
#include<unordered_map>
#define int long long 

using namespace std;
int n;
bool check(int k){
    int count =0;
    //count = k+ C(k,2)
    return k+k*(k-1)/2 >= n;
}
signed main(){
    cin>>n;
    int mink = n;
    int l = 0,r=n;
    while(l<=r){
        int mid = l+((r-l)>>1);
        if(check(mid)){
            mink = min(mink,mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<mink;
    return 0;

}