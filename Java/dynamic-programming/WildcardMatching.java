public class WildcardMatching {

    // Function to check if string s matches pattern p
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();

        // DP table: dp[i][j] = does s[0..i-1] match p[0..j-1] ?
        boolean[][] dp = new boolean[n + 1][m + 1];

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Fill for patterns that start with '*'
        // e.g., s = "" and p = "***" should be true
        for (int j = 1; j <= m; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can represent empty string
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char sc = s.charAt(i - 1); // current char in string
                char pc = p.charAt(j - 1); // current char in pattern

                if (pc == sc || pc == '?') {
                    // If chars match OR '?' wildcard, carry forward diagonal
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pc == '*') {
                    // '*' can represent:
                    // 1. empty sequence -> dp[i][j-1]
                    // 2. one or more characters -> dp[i-1][j]
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false; // mismatch
                }
            }
        }

        // Answer is whether entire s matches entire p
        return dp[n][m];
    }

    // ----------------------------
    // Example Usage
    // ----------------------------
    public static void main(String[] args) {
        WildcardMatching solver = new WildcardMatching();

        System.out.println(solver.isMatch("aa", "a"));   // false
        System.out.println(solver.isMatch("aa", "*"));   // true
        System.out.println(solver.isMatch("cb", "?a"));  // false
        System.out.println(solver.isMatch("adceb", "*a*b")); // true
        System.out.println(solver.isMatch("acdcb", "a*c?b")); // false
    }
}
