/*
Problem statement : 

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
  Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // check if placing queen at (row,col) is safe
    bool isSafe(vector<vector<int>>& board, int row, int col) {
        int x = row, y = col;
        while (y >= 0) if (board[x][y--] == 1) return false;
        x = row; y = col;
        while (x < board.size() && y >= 0) if (board[x++][y--] == 1) return false;
        x = row; y = col;
        while (x >= 0 && y >= 0) if (board[x--][y--] == 1) return false;
        return true;
    }

    // convert board to string format
    void addSol(vector<vector<int>>& board, int n, vector<vector<string>>& ans) {
        vector<string> arr;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < n; j++)
                str.push_back(board[i][j] ? 'Q' : '.');
            arr.push_back(str);
        }
        ans.push_back(arr);
    }

    // backtrack to find all solutions
    void solve(vector<vector<int>>& board, int n, int col, vector<vector<string>>& ans) {
        if (col == n) { addSol(board, n, ans); return; }
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 1;
                solve(board, n, col + 1, ans);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(board, n, 0, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    Solution s;
    auto res = s.solveNQueens(n);
    cout << "Total Solutions: " << res.size() << "\n\n";
    for (auto& sol : res) {
        for (auto& row : sol)
            cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
