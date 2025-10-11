// Recursive
#include <iostream>
#include <vector>
using namespace std;

class SolutionRecursive
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        int oneStep = climbStairs(n - 1);
        int twoStep = climbStairs(n - 2);
        return oneStep + twoStep;
    }
};

// Memoization
class SolutionMemo
{
private:
    int func(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = func(n - 1, dp) + func(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }
};

// Tabulation
class SolutionTab
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Space optimization
class SolutionOpt
{
public:
    int climbStairs(int n)
    {
        int prev2 = 1;
        int prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main()
{
    // You can choose which solution to use by changing the class name below
    SolutionOpt sol;
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}