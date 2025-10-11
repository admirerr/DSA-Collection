// Longest Palindromic Substring
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string str) {
        int start = 0, end = 0;

        // Iterate through each character as center
        for (int center = 0; center < str.length(); center++) {
            // Expand around odd length palindrome
            int lenOdd = expandFromCenter(str, center, center);
            // Expand around even length palindrome
            int lenEven = expandFromCenter(str, center, center + 1);
            // Get the max of both lengths
            int maxLen = max(lenOdd, lenEven);

            // Update the longest palindrome boundaries
            if (maxLen > end - start) {
                start = center - (maxLen - 1) / 2;
                end = center + maxLen / 2;
            }
        }

        // Return the longest palindromic substring
        return str.substr(start, end - start + 1);
    }

private:
    int expandFromCenter(const string& str, int left, int right) {
        // Expand while characters match and within bounds
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};

int main() {
    Solution sol;
    string input = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input) << endl;
    return 0;
}
