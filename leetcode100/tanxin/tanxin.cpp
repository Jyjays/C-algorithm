#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int min_price = INT_MAX;
    int n = prices.size();
    for (int i = 0; i < n; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else if (prices[i] - min_price > profit){
            profit = prices[i] - min_price;
        }
    }
    return profit;
}
bool canJump(vector<int> &nums) {
    int max_reach = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > max_reach) return false;
        max_reach = max(max_reach, i + nums[i]);
    }
    return true;
}

int jump(vector<int>& nums) {
    int max_reach = 0;
    int step = 0;
    int end = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        max_reach = max(max_reach, i + nums[i]);
        if (i == end) {
            end = max_reach;
            step++;
        }
    }
    return step;
}

vector<int> partitionLabels(string s) { 
    int last[26];
    int n = s.size();
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }       
    return res;
}
int main() {
    return 0;
}