#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int y = -1;
        if (nums.size() == 1)
            return;

        // Step 1: find the first decreasing element from the end
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                y = i;
                break;
            }
        }

        // Step 2: if found, swap it with the next larger element from the end
        if (y != -1)
        {
            for (int j = nums.size() - 1; j > y; j--)
            {
                if (nums[y] < nums[j])
                {
                    swap(nums[y], nums[j]);
                    break;
                }
            }
            // Step 3: reverse the part after index y
            rev(nums, y + 1, nums.size() - 1);
        }
        else
        {
            // If no such index found, reverse the whole array
            rev(nums, 0, nums.size() - 1);
        }
    }

    void rev(vector<int> &nums, int l, int r)
    {
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};

    cout << "Original permutation: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    s.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
