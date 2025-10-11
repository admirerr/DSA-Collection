#include <bits/stdc++.h>
using namespace std;

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    dp[0][0][0] = grid[0][0];

    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 < n; c1++) {
            for (int r2 = 0; r2 < n; r2++) {
                int c2 = r1 + c1 - r2;
                if (c2 < 0 || c2 >= n) continue;
                if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                int val = grid[r1][c1];
                if (r1 != r2 || c1 != c2) val += grid[r2][c2];

                int best = INT_MIN;
                if (r1 > 0 && r2 > 0) best = max(best, dp[r1-1][c1][r2-1]);
                if (r1 > 0 && c2 > 0) best = max(best, dp[r1-1][c1][r2]);
                if (c1 > 0 && r2 > 0) best = max(best, dp[r1][c1-1][r2-1]);
                if (c1 > 0 && c2 > 0) best = max(best, dp[r1][c1-1][r2]);

                if (best != INT_MIN) dp[r1][c1][r2] = best + val;
            }
        }
    }

    return max(0, dp[n-1][n-1][n-1]);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    cout << cherryPickup(grid) << endl;
}
