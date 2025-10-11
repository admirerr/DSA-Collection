public class SudokuSolver  {
    public static boolean sudokuSolver(int[][] sudoku, int row, int column) {
        // basecase
        if (row == 9 ) {
            return true;// final solution already got
        } 

        // recursion
        int nextRow = row, nextCol = column + 1;

        if (column + 1 == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }
        if (sudoku[row][column] != 0) {// for already set elements
           return sudokuSolver(sudoku, nextRow, nextCol);
        }
        for (int digit = 1; digit<=9; digit++) {
            if (isSafe(sudoku, row, column, digit)) {
                sudoku[row][column] = digit;
                if (sudokuSolver(sudoku, nextRow, nextCol)) {
                    return true;// soltion exists
                }
                sudoku[row][column] = 0;// if no solution
            }

        }

        return false;

    }

    public static boolean isSafe(int[][] sudoku,int row, int column, int digit) {
        // column
        for (int i = 0; i <= 8; i++) {
            if (sudoku[i][column] == digit) {
                return false;
            }
        }

        // row

        for (int j = 0; j <= 8; j++) {
            if (sudoku[row][j] == digit) {
                return false;
            }
        }

        // grid-3*3
        int startingRow = (row / 3) * 3;
        int startingColumn = (column / 3) * 3;
        for (int i = startingRow; i < startingRow + 3; i++) {
            for (int j = startingColumn; j < startingColumn + 3; j++) {
                if (sudoku[i][j] == digit) {
                    return false;
                }
            }

        }

        return true;
    }
public static void printSudoku(int [][] sudoku){
    for(int i=0 ;i<9 ;i++){
        for(int j=0 ;j<9 ;j++){
            System.out.print(sudoku[i][j]+" ");
        }
        System.out.println();
    }
}
    public static void main(String[] args) {
        int[][] sudoku = {
                { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
        };

        if(sudokuSolver(sudoku, 0, 0)){
            System.out.println("the solution exists");
            printSudoku(sudoku);
        }
        else{
            System.out.println("the solution does not exists");
        }
    }
}


