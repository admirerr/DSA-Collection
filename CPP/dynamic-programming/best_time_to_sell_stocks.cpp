#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxp = 0;
        int mini = prices[0];
        for (int i = 0; i < n; i++)
        {
            int curProfit = prices[i] - mini;
            maxp = max(maxp, curProfit);
            mini = min(mini, prices[i]);
        }
        return maxp;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
