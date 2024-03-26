#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private: 
    bool check(vector<int>& stones,int k){
        cout<<k<<endl;
        int n = stones.size();
        vector<bool> used(n,false);
        //第一次跳跃
        for(int i=0,j=1;j<stones.size();j++){
            while(j<stones.size()&&stones[j] - stones[i] <= k){
                j++;  
            }
            i = j-1;   //如果j在最后一次满足了条件那么还会多加一次，所以要减去1     
            used[i] = true;
            cout<<stones[i]<<" ";
        }
        used[n-1] = false;
        //第二次跳跃
        for(int i =0,j = 1;j<stones.size();j++){
            while(used[j] &&j< n){
                j++;   //找到可用的石头
            }
            if(stones[j] - stones[i]>k) return false;
            i = j;
            cout<<stones[i]<<" ";
        }
        return true;
    }
public:
    int maxJump(vector<int>& stones) {
        int l = 0,r = stones[stones.size()-1];
        while(l< r){
            int mid = l+ ((r-l)>>1);
            if(check(stones,mid)){
                r = mid ;
            }else{
                l = mid +1;
            }
            cout<<endl;
        }
        return r;
    }
    
};
int n;
int main(){
    vector<int> stones = {0,2,5,6,7};
    Solution s;
    cout<<s.maxJump(stones);
    return 0;
}