#include <iostream>
#include <vector>
#include <functional>
using namespace std;

bool isMonotonic(vector<int> &nums)
{
    int length = nums.size();

    auto isUp = [](const vector<int> &nums, int length) 
    {
        if (nums[0] < nums[1])
        {
            return true;
        }
        else if (nums[0] > nums[1])
        {
            return false;
        }
        else
        {
            size_t i = 1;
            while (nums[i] == nums[i + 1] && i + 1 < length)
            {
                ++i;
            }
            return nums[i] < nums[i + 1];
        }
    };

    bool flag = isUp(nums, length); 

    if (flag)
    {
        for (size_t i = 2; i < length; i++)
        {
            if (nums[i - 1] > nums[i])
                return false;
        }
    }
    else
    {
        for (size_t i = 2; i < length; i++)
        {
            if (nums[i - 1] < nums[i])
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1};
    cout << isMonotonic(nums) << endl;
    return 0;
}