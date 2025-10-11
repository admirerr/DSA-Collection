#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Space Optimization version
class Solution {
public:
    int editDistance(string start, string target) {
        int n = start.size();
        int m = target.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; j++) prev[j] = j;
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (start[i - 1] == target[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j - 1], min(curr[j - 1], prev[j]));
            }
            prev = curr;
        }
        return curr[m];
    }
};

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    Solution sol;
    int result = sol.editDistance(s1, s2);
    cout << "Edit Distance: " << result << endl;
    return 0;
}
