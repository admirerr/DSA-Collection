#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Space Optimization version (most efficient)
class Solution
{
public:
    int unboundedKnapsack(vector<int> &weight, vector<int> &value, int n, int target)
    {
        vector<int> prev(target + 1, 0);
        for (int i = weight[0]; i <= target; i++)
        {
            prev[i] = (i / weight[0]) * value[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int nott = 0 + prev[tar];
                int take = INT_MIN;
                if (weight[i] <= tar)
                    take = value[i] + prev[tar - weight[i]];
                prev[tar] = max(nott, take);
            }
        }
        return prev[target];
    }
};

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; ++i)
        cin >> wt[i];
    cout << "Enter values: ";
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    cout << "Enter knapsack capacity: ";
    cin >> W;

    Solution sol;
    int result = sol.unboundedKnapsack(wt, val, n, W);
    cout << "Maximum value: " << result << endl;
    return 0;
}
