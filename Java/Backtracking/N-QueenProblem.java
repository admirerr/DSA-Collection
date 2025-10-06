import java.util.*;

// N-Queen Problem

class Queen {
    private boolean canPlace(char[][] board, int row, int col, int n) {
        // upper-left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) 
            if (board[r][c] == 'Q') return false;

        // same row (left)
        for (int c = col; c >= 0; c--) 
            if (board[row][c] == 'Q') return false;

        // bottom-left diagonal
        for (int r = row, c = col; r < n && c >= 0; r++, c--) 
            if (board[r][c] == 'Q') return false;

        return true;
    }

    private void placements(int col, char[][] board, List<List<String>> ans, int n) {
        if (col == n) {
            List<String> temp = new ArrayList<>();
            for (int i = 0; i < n; i++) temp.add(new String(board[i]));
            ans.add(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (canPlace(board, row, col, n)) {
                board[row][col] = 'Q';
                placements(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) Arrays.fill(board[i], '.');
        placements(0, board, ans, n);
        return ans;
    }
}