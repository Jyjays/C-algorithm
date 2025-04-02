#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    int len = intervals.size();

    if (len <= 1) return intervals;
    auto cmp  = [](vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    };
    auto tmp = intervals;
    sort (tmp.begin(),tmp.end(),cmp);
    
    
    int cur_l = tmp[0][0], cur_r = tmp[0][1];
    for (int i = 1; i< len; i++) {
        if (cur_r >= tmp[i][0]) {
            cur_r = max(cur_r,tmp[i][1]);
        } else {
            res.push_back({cur_l,cur_r});
            cur_l = tmp[i][0];
            cur_r = tmp[i][1];
        }
    }
    res.push_back({cur_l,cur_r});
    return res;
}

int main () {
    int n;
    cin >> n;
    vector<vector<int>> intervals;
    for (int i = 0; i< n; i++) {
        vector<int> num(2);
        cin >> num[0] >> num[1];
        intervals.push_back(num);
    }
    auto res= merge(intervals);
    for (int i = 0 ;i< res.size(); i++) {
        cout << res[i][0] << " " << res[i][1]<< " ";
    }
    return 0;
}
