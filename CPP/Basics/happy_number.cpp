// Problem: Happy Number
// Language: C++
// Problem: Happy Number (IEEEXtreme / LeetCode 202 style)
// Description:
//   A number is "happy" if repeatedly replacing the number by the sum of the
//   squares of its digits eventually leads to 1. If the process enters a
//   cycle that does not include 1, the number is not happy.
// Input/Output for this implementation:
//   - This program reads a single positive integer n from stdin,
//     computes whether n is a happy number, and prints "YES" if happy,
//     otherwise prints "NO".
// Complexity:
//   - Each transformation is O(d) where d = number of digits (<= log10 n).
//   - For base-10 the sequence enters a cycle within limited bounds; overall
//     expected time is small; space O(1) (Floyd cycle-detection) or O(k) if
//     using a set where k is number of visited states.

#include <bits/stdc++.h>
using namespace std;

// compute sum of squares of digits of x
long long sum_of_squares(long long x) {
    long long s = 0;
    while (x > 0) {
        int d = x % 10;
        s += 1LL * d * d;
        x /= 10;
    }
    return s;
}

// Approach 1: Floyd's cycle detection (tortoise & hare).
// If the sequence reaches 1 -> happy. If cycle forms and doesn't include 1 -> not happy.
bool isHappy(long long n) {
    auto next = [](long long x){ return sum_of_squares(x); };

    long long tortoise = n;
    long long hare = n;
    while (true) {
        tortoise = next(tortoise);         // move by 1
        hare = next(next(hare));          // move by 2
        if (tortoise == 1 || hare == 1) return true;
        if (tortoise == hare) return false; // cycle detected
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        cout << "NO\n";
        return 0;
    }

    cout << (isHappy(n) ? "YES\n" : "NO\n");
    return 0;
}

/*
Sample:
Input:
19
Output:
YES

Explanation:
19 -> 1^2 + 9^2 = 82
82 -> 8^2 + 2^2 = 68
68 -> 6^2 + 8^2 = 100
100 -> 1^2 + 0 + 0 = 1  -> happy