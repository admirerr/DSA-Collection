#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.length()) {
        if (seen.find(s[right]) == seen.end()) {
            // Character not in set
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            // Duplicate found, remove from left
            seen.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Longest substring length without repeating characters: " << result << endl;

    return 0;
}
