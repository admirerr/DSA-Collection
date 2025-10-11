#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

// Space Optimized Solution
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev = 0, prev2 = 0;
        for(int i = 1; i < n; i++) {
            int fs = prev + abs(heights[i] - heights[i-1]);
            int ss = INT_MAX;
            if(i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);
            int curr = min(fs, ss);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main() {
    int n;
    cout << "Enter number of stones: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter heights: ";
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    Solution sol;
    int result = sol.frogJump(heights);
    cout << "Minimum energy: " << result << endl;
    return 0;
}
