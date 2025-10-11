"""
n_queens.py
------------
Python solution for the N-Queens Problem using backtracking.

Description:
- The program places N queens on an N x N chessboard so that no two queens attack each other.
- It prints all possible solutions and the total number of solutions.

Usage:
    python n_queens.py
"""

def print_board(board):
    """Print the chessboard configuration."""
    for row in board:
        print(" ".join(row))
    print("\n")


def is_safe(board, row, col, n):
    """Check if placing a queen at (row, col) is safe."""
    # Check this column
    for i in range(row):
        if board[i][col] == "Q":
            return False

    # Check upper-left diagonal
    i, j = row - 1, col - 1
    while i >= 0 and j >= 0:
        if board[i][j] == "Q":
            return False
        i -= 1
        j -= 1

    # Check upper-right diagonal
    i, j = row - 1, col + 1
    while i >= 0 and j < n:
        if board[i][j] == "Q":
            return False
        i -= 1
        j += 1

    return True


def solve_n_queens(board, row, n, solutions):
    """Backtracking function to solve N-Queens problem."""
    if row == n:
        # Found a solution, add a copy to solutions list
        solution = ["".join(r) for r in board]
        solutions.append(solution)
        print_board(board)
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = "Q"
            solve_n_queens(board, row + 1, n, solutions)
            board[row][col] = "."  # backtrack


def main():
    n = int(input("Enter the number of queens (N): "))
    board = [["." for _ in range(n)] for _ in range(n)]
    solutions = []
    print(f"\nAll possible solutions for {n}-Queens problem:\n")
    solve_n_queens(board, 0, n, solutions)
    print(f"Total solutions found: {len(solutions)}")


if __name__ == "__main__":
    main()
