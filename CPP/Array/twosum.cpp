// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] + nums[i] == target)
                {
                    v = {j, i};
                    return v;
                }
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = s.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No two numbers found that add up to target." << endl;
    }

    return 0;
}
