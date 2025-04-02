#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


    vector<int> productExceptSelf(vector<int> &nums){
        int len = nums.size();
        vector<int> pre(len);
        vector<int> sub(len);
        pre[0] = 1, sub[len-1] = 1;
        for (int i = 1; i< len; i++) {
            pre[i] = pre[i-1] * nums[i-1]; 
        }
        for (int i = len -2;i >=0;i--) {
            sub[i] = sub[i+1] * nums[i+1];
        }
        vector<int> res(len);
        for (int i = 0; i< len;i++) {
            res[i] = pre[i] * sub[i];
        }
        return res;
    }

int main () {

}