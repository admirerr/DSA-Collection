#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find('*');              // position of '*'
        string b = p.substr(0, x);        // prefix before '*'
        string e = p.substr(x + 1);       // suffix after '*'

        int i = s.find(b);                // find prefix in s
        int j = s.rfind(e);               // find suffix in s (from right)

        // check prefix found, suffix found, and prefix ends before suffix starts
        return i != -1 && j != -1 && i + b.size() <= j;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "leetcode";
    string p1 = "ee*e";
    cout << (sol.hasMatch(s1, p1) ? "true" : "false") << endl; // true

    // Example 2
    string s2 = "car";
    string p2 = "c*v";
    cout << (sol.hasMatch(s2, p2) ? "true" : "false") << endl; // false

    // Example 3
    string s3 = "luck";
    string p3 = "u*";
    cout << (sol.hasMatch(s3, p3) ? "true" : "false") << endl; // true

    return 0;
}
