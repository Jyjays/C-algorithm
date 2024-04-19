#include<bits/stdc++.h>

#define int long long
using namespace std;

int n, tar;
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int mid;
    while (left <= right)
    {

        mid = left + ((right - left) >> 1);
        cout<<mid<<" ";
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

signed main()
{
    //cin >> n >> tar;
    vector<int> nums = {-1,0,3,5,9,12};
    int num;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> num;
    //     nums.push_back(num);
    // }
    int res = search(nums, tar);
    cout << res;
    return 0;
}
