#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int newLength = s.removeElement(nums, val);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing " << val << ": ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
