#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int numberToPut) {
        // check horizontally
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '0' + numberToPut)
                return false;
        }

        // check vertically
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '0' + numberToPut)
                return false;
        }

        // check between 3 X 3
        int startCol = (col / 3) * 3;
        int startRow = (row / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == '0' + numberToPut) {
                    return false;
                }
            }
        }

        return true;
    }

    bool putNumberFromZeroToNine(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 1; num < 10; num++) {
                        if (isSafe(board, i, j, num)) {
                            board[i][j] = '0' + num; // Place the number

                            // Recurse: try to solve the rest of the board
                            if (putNumberFromZeroToNine(board)) {
                                return true; // solution found
                            } else {
                                // Backtrack if this path fails
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false; // no valid number possible
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        putNumberFromZeroToNine(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    // before 
    cout << "Before" << endl;
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    Solution s;
    s.solveSudoku(board);

    // print solved sudoku
    cout << "After" << endl;
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout <<  endl;

    return 0;
}
