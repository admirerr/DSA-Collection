#include <bits/stdc++.h>
using namespace std;

int eggDrop(int eggs, int floors) {
    vector<int> dp(floors + 1, 0), prev(floors + 1, 0);

    for (int e = 1; e <= eggs; e++) {
        for (int f = 1; f <= floors; f++) {
            if (e == 1) {
                dp[f] = f; 
            } else {
                dp[f] = INT_MAX;
                for (int k = 1; k <= f; k++) {
                    int res = 1 + max(prev[k - 1], dp[f - k]);
                    dp[f] = min(dp[f], res);
                }
            }
        }
        prev = dp;
    }
    return dp[floors];
}

int main() {
    int eggs = 2, floors = 10;
    cout << "Minimum number of trials in worst case: " 
         << eggDrop(eggs, floors) << endl;
    return 0;
}
