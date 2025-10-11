/**
 * Sudoku Solver using Backtracking
 * * Problem: Given a partially filled 9x9 Sudoku grid, solve the puzzle 
 * by placing digits 1-9 in the empty cells (represented by 0) 
 * such that the rules of Sudoku are satisfied.
 */

// --- 1. isSafe Function  ---
/**
 * Checks if placing a given digit at the specified row and column is valid 
 * according to Sudoku rules (Row, Column, and 3x3 Grid).
 * * @param {number[][]} sudoku The 9x9 grid array.
 * @param {number} row The current row index.
 * @param {number} col The current column index.
 * @param {number} digit The digit (1-9) to check.
 * @returns {boolean} True if the placement is safe, false otherwise.
 */
function isSafe(sudoku, row, col, digit) {
    // Check Column (from row 0 to 8)
    for (let i = 0; i < 9; i++) {
        if (sudoku[i][col] === digit) {
            return false;
        }
    }

    // Check Row (from column 0 to 8)
    for (let j = 0; j < 9; j++) {
        if (sudoku[row][j] === digit) {
            return false;
        }
    }

    // Check 3x3 Grid
    const startingRow = Math.floor(row / 3) * 3;
    const startingCol = Math.floor(col / 3) * 3;

    for (let i = startingRow; i < startingRow + 3; i++) {
        for (let j = startingCol; j < startingCol + 3; j++) {
            if (sudoku[i][j] === digit) {
                return false;
            }
        }
    }

    return true;
}

// --- 2. sudokuSolver Function (Backtracking Logic) ---
/**
 * Recursive backtracking function to solve the Sudoku puzzle.
 * * @param {number[][]} sudoku The 9x9 grid array.
 * @param {number} row The current row index (0-8).
 * @param {number} col The current column index (0-8).
 * @returns {boolean} True if a solution is found, false otherwise.
 */
function sudokuSolver(sudoku, row, col) {
    // BASE CASE: If we have successfully processed all rows (row index reaches 9)
    if (row === 9) {
        return true;
    }

    // Calculate the next cell (move right, or wrap to the next row)
    let nextRow = row;
    let nextCol = col + 1;

    if (col + 1 === 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // CASE 1: Cell is already filled (not 0), so we move to the next cell.
    if (sudoku[row][col] !== 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    // CASE 2: Cell is empty (0), so we try digits 1 through 9.
    for (let digit = 1; digit <= 9; digit++) {
        if (isSafe(sudoku, row, col, digit)) {
            // Place the digit (Assumption)
            sudoku[row][col] = digit;
            
            // Recurse to the next cell
            if (sudokuSolver(sudoku, nextRow, nextCol)) {
                return true; // Solution found!
            }
            
            // Backtrack: If the current assumption failed, reset the cell to 0.
            sudoku[row][col] = 0;
        }
    }

    // If no digit from 1-9 worked in this cell, return false.
    return false;
}

// --- 3. Utility Function (Printing) ---
function printSudoku(sudoku) {
    for (let i = 0; i < 9; i++) {
        console.log(sudoku[i].join(" "));
    }
}

// --- 4. Main Execution and Example ---
function main() {
    // Example puzzle: 0 represents an empty cell
    let sudoku = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ];

    console.log("--- Starting Sudoku Puzzle ---");
    printSudoku(sudoku);

    if (sudokuSolver(sudoku, 0, 0)) {
        console.log("\n--- Solution Exists ---");
        printSudoku(sudoku);
    } else {
        console.log("\nSolution does not exist.");
    }
}

main();


