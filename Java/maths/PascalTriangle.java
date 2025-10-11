public final class PascalTriangle {
    private PascalTriangle() {
    }

    public static int[][] pascal(int n) {
        int[][] arr = new int[n][n];

        for (int line = 0; line < n; line++) {
            for (int i = 0; i <= line; i++) {
                if (line == i || i == 0) {
                    arr[line][i] = 1;
                } else {
                    arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
                }
            }
        }
        return arr;
    }

    public static void printTriangle(int[][] triangle) {
        int rows = triangle.length;
        for (int i = 0; i < rows; i++) {
            // Add spacing for alignment
            for (int j = 0; j < rows - i; j++) {
                System.out.print("  ");
            }
            // Print numbers
            for (int j = 0; j <= i; j++) {
                System.out.printf("%4d", triangle[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int numberOfRows = 9;
        System.out.println("Generating Pascal's Triangle with " + numberOfRows + " rows:");

        int[][] triangle = pascal(numberOfRows);
        printTriangle(triangle);
    }
}