// Problem: Happy Number
// Language: C++
// Description:
//   A number is "happy" if repeatedly replacing the number by the sum
//   of the squares of its digits eventually leads to 1. If it enters
//   a cycle that does not include 1, the number is not happy.
// Input: A single positive integer n
// Output: "YES" if n is a happy number, otherwise "NO"

#include <iostream>

using namespace std;

// Function to compute the sum of squares of digits
long long sum_of_squares(long long x) {
    long long s = 0;
    while (x > 0) {
        int d = static_cast<int>(x % 10);
        s += static_cast<long long>(d) * d;
        x /= 10;
    }
    return s;
}

// Floyd's cycle detection algorithm
bool isHappy(long long n) {
    auto next = [](long long x) {
        long long s = 0;
        while (x > 0) {
            int d = static_cast<int>(x % 10);
            s += static_cast<long long>(d) * d;
            x /= 10;
        }
        return s;
    };

    long long tortoise = n;
    long long hare = n;

    while (true) {
        tortoise = next(tortoise);
        hare = next(next(hare));
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
Sample Input:
19
Sample Output:
YES
*/
