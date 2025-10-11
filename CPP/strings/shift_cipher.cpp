/*
Problem Name: Shift Cipher
Language: C++
Description:
    Given N test cases. For each test case:
    - Read an integer k (the shift value).
    - Read a string t (the text).
    - If the word "the" appears as a separate word in t, shift letters backward by k.
    - Otherwise, shift letters forward by k.
    - Spaces and non-alphabetic characters remain unchanged.

Approach:
    - Iterate over each character.
    - Check if it is an alphabet; shift it accordingly using ASCII values.
    - Use modulo 26 arithmetic for wrap-around.
    - Before shifting, determine if the word "the" exists in the string.

Example Input:
2
3
hello world
1
the cat is here

Example Output:
khoor zruog
sfd bzs hr ifsf

Time Complexity: O(L) per test case (L = length of string)
Space Complexity: O(L)
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform the shift cipher
string shiftCipher(const string &text, int k, int direction) {
    string result;
    result.reserve(text.size());

    for (char c : text) {
        if (c == ' ') {
            result += ' ';
        } else if (isalpha(static_cast<unsigned char>(c))) {
            char base = isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
            int shifted = ((c - base) + direction * k) % 26;
            if (shifted < 0) shifted += 26;  // handle negative modulo
            result += static_cast<char>(shifted + base);
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore(); // consume newline

    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        cin.ignore();

        string t;
        getline(cin, t);

        // Check if "the" appears as a word (case-insensitive)
        bool containsThe = false;
        string word;
        for (size_t j = 0; j <= t.size(); ++j) {
            if (j == t.size() || t[j] == ' ') {
                if (!word.empty() && word == "the") {
                    containsThe = true;
                    break;
                }
                word.clear();
            } else {
                word += tolower(static_cast<unsigned char>(t[j]));
            }
        }

        // Direction: -1 if "the" found, +1 otherwise
        cout << shiftCipher(t, k, containsThe ? -1 : 1) << '\n';
    }

    return 0;
}
