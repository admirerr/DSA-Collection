#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursion
class SolutionRecursion
{
private:
    bool isall(string &pat, int m)
    {
        for (int i = 0; i <= m; i++)
        {
            if (pat[i] != '*')
                return false;
        }
        return true;
    }
    bool func(int n, int m, string &str, string &pat)
    {
        if (n < 0 && m < 0)
            return true;
        if (m < 0)
            return false;
        if (n < 0)
            return isall(pat, m);
        if (str[n] == pat[m] || pat[m] == '?')
        {
            return func(n - 1, m - 1, str, pat);
        }
        if (pat[m] == '*')
        {
            return func(n - 1, m, str, pat) || func(n, m - 1, str, pat);
        }
        return false;
    }

public:
    bool wildCard(string str, string pat)
    {
        int n = str.size();
        int m = pat.size();
        return func(n - 1, m - 1, str, pat);
    }
};

// Memoization
class SolutionMemo
{
private:
    bool isall(string &pat, int m)
    {
        for (int i = 0; i <= m; i++)
        {
            if (pat[i] != '*')
                return false;
        }
        return true;
    }
    bool func(int n, int m, string &str, string &pat, vector<vector<int>> &dp)
    {
        if (n < 0 && m < 0)
            return true;
        if (m < 0)
            return false;
        if (n < 0)
            return isall(pat, m);
        if (dp[n][m] != -1)
            return dp[n][m];
        if (str[n] == pat[m] || pat[m] == '?')
        {
            return dp[n][m] = func(n - 1, m - 1, str, pat, dp);
        }
        if (pat[m] == '*')
        {
            return dp[n][m] = func(n - 1, m, str, pat, dp) || func(n, m - 1, str, pat, dp);
        }
        return dp[n][m] = false;
    }

public:
    bool wildCard(string str, string pat)
    {
        int n = str.size();
        int m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return func(n - 1, m - 1, str, pat, dp);
    }
};

// Tabulation
class SolutionTabulation
{
public:
    bool wildCard(string str, string pat)
    {
        int n = str.size();
        int m = pat.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            if (pat[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class SolutionSpaceOpt
{
public:
    bool wildCard(string str, string pat)
    {
        int n = str.size();
        int m = pat.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++)
        {
            if (pat[j - 1] == '*')
            {
                prev[j] = prev[j - 1];
            }
            else
            {
                prev[j] = false;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            curr[0] = false;
            for (int j = 1; j <= m; j++)
            {
                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (pat[j - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main()
{
    string str, pat;
    cout << "Enter string: ";
    cin >> str;
    cout << "Enter pattern: ";
    cin >> pat;

    // Uncomment the solution you want to use:
    // SolutionRecursion sol;
    // SolutionMemo sol;
    // SolutionTabulation sol;
    SolutionSpaceOpt sol;

    bool result = sol.wildCard(str, pat);
    cout << (result ? "Match" : "No Match") << endl;
    return 0;
}
