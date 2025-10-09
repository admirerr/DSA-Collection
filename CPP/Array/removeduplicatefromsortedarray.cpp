#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0; // Handle empty vector case

        int r = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[r - 1])
            {
                nums[r] = nums[i];
                r++;
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int newLength = s.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
