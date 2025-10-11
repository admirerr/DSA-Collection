// Problem: Coin Change - Minimum number of coins needed to make a given amount
// Given an array of coin denominations and a target amount, find the minimum number of coins needed

import java.util.*;

public class CoinChange {

    public static int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }

    // Also solve the variation: number of ways to make change
    public static int coinChangeWays(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of coin types: ");
        int n = sc.nextInt();

        int[] coins = new int[n];
        System.out.print("Enter coin denominations: ");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        System.out.print("Enter target amount: ");
        int amount = sc.nextInt();

        int minCoins = coinChange(coins, amount);
        int ways = coinChangeWays(coins, amount);

        if (minCoins == -1) {
            System.out.println("Cannot make change for " + amount);
        } else {
            System.out.println("Minimum coins needed: " + minCoins);
        }

        System.out.println("Number of ways to make change: " + ways);

        sc.close();
    }
}