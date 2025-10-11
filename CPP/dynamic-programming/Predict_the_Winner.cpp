#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    dp[i][j] = 0;
                } else {
                    int leftPicked  = nums[i] - ((i + 1 < n) ? dp[i + 1][j] : 0);
                    int rightPicked = nums[j] - ((j - 1 >= 0) ? dp[i][j - 1] : 0);
                    dp[i][j] = max(leftPicked, rightPicked);
                }
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 5, 2};
    cout << "Example 1: " << (sol.predictTheWinner(nums1) ? "true" : "false") << endl;
    // Output: false

    // Example 2
    vector<int> nums2 = {1, 5, 233, 7};
    cout << "Example 2: " << (sol.predictTheWinner(nums2) ? "true" : "false") << endl;
    // Output: true

    // Example 3
    vector<int> nums3 = {2, 4, 55, 6, 8};
    cout << "Example 3: " << (sol.predictTheWinner(nums3) ? "true" : "false") << endl;
    // Output: false

    return 0;
}
