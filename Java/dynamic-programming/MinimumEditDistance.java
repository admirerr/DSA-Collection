public class MinimumEditDistance {
    public static void main(String[] args) {
        String str1 = "kitten";
        String str2 = "sitting";
        System.out.println("Minimum Edit Distance between \"" + str1 + "\" and \"" + str2 + "\" is: " + minEditDistance(str1, str2));
    }

    public static int minEditDistance(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j; // Insert all characters of str2
                } else if (j == 0) {
                    dp[i][j] = i; // Remove all characters of str1
                } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], // Remove
                                    Math.min(dp[i][j - 1], // Insert
                                             dp[i - 1][j - 1])); // Replace
                }
            }
        }
        return dp[m][n];
    }
}
