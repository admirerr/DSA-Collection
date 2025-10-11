import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class KnightsTour {
    private static final int BASE = 12;
    private static final int[][] MOVES = {
        {1, -2}, {2, -1}, {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
    };

    static int[][] grid;
    static int total;

    public static void resetBoard() {
        grid = new int[BASE][BASE];
        total = (BASE - 4) * (BASE - 4);
        for (int r = 0; r < BASE; r++) {
            for (int c = 0; c < BASE; c++) {
                if (r < 2 || r > BASE - 3 || c < 2 || c > BASE - 3) {
                    grid[r][c] = -1;
                }
            }
        }
    }

    static boolean solve(int row, int column, int count) {
        if (count > total) {
            return true;
        }
        List<int[]> neighbor = neighbors(row, column);
        if (neighbor.isEmpty() && count != total) {
            return false;
        }
        neighbor.sort(Comparator.comparingInt(a -> a[2]));
        for (int[] nb : neighbor) {
            int nextRow = nb[0];
            int nextCol = nb[1];
            grid[nextRow][nextCol] = count;
            if (!orphanDetected(count, nextRow, nextCol) && solve(nextRow, nextCol, count + 1)) {
                return true;
            }
            grid[nextRow][nextCol] = 0;
        }
        return false;
    }

    static List<int[]> neighbors(int row, int column) {
        List<int[]> neighbour = new ArrayList<>();
        for (int[] m : MOVES) {
            int x = m[0];
            int y = m[1];
            if (row + y >= 0 && row + y < BASE && column + x >= 0 && column + x < BASE && grid[row + y][column + x] == 0) {
                int num = countNeighbors(row + y, column + x);
                neighbour.add(new int[] {row + y, column + x, num});
            }
        }
        return neighbour;
    }

    static int countNeighbors(int row, int column) {
        int num = 0;
        for (int[] m : MOVES) {
            int x = m[0];
            int y = m[1];
            if (row + y >= 0 && row + y < BASE && column + x >= 0 && column + x < BASE && grid[row + y][column + x] == 0) {
                num++;
            }
        }
        return num;
    }

    static boolean orphanDetected(int count, int row, int column) {
        if (count < total - 1) {
            List<int[]> neighbor = neighbors(row, column);
            for (int[] nb : neighbor) {
                if (countNeighbors(nb[0], nb[1]) == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        resetBoard();
        grid[2][2] = 1;
        if (solve(2, 2, 2)) {
            for (int r = 2; r < BASE - 2; r++) {
                for (int c = 2; c < BASE - 2; c++) {
                    System.out.printf("%3d ", grid[r][c]);
                }
                System.out.println();
            }
        } else {
            System.out.println("No solution found.");
        }
    }
}

