public class KnapsackProblem {
    public static void main(String[] args) {
        int[] weights = {1, 2, 3};
        int[] values = {10, 15, 40};
        int capacity = 6;
        System.out.println("Maximum value in Knapsack = " + knapsack(weights, values, capacity));
    }

    public static int knapsack(int[] weights, int[] values, int capacity) {
        int n = weights.length;
        int[][] dp = new int[n + 1][capacity + 1];

        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0; // Base case: no items or no capacity
                } else if (weights[i - 1] <= w) {
                    dp[i][w] = Math.max(dp[i - 1][w], // Exclude the item
                                        dp[i - 1][w - weights[i - 1]] + values[i - 1]); // Include the item
                } else {
                    dp[i][w] = dp[i - 1][w]; // Exclude the item
                }
            }
        }
        return dp[n][capacity];
    }
}
