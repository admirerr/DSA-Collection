#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int k = nums.size() - 1;
        vector<int> v(2, 0);
        int f = 0, l = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (f == 0 && nums[i] == target)
            {
                v[0] = i;
                f = 1;
            }
            if (l == 0 && nums[k] == target)
            {
                v[1] = k;
                l = 1;
            }
            if (f == 1 && l == 1)
                return v;
            k--;
        }

        // If not found
        v = {-1, -1};
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = s.searchRange(nums, target);

    cout << "Target " << target << " found at range: ["
         << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
