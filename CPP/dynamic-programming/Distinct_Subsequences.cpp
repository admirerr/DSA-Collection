#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Paste your Solution class here (choose one implementation, e.g., Tabulation)
class Solution {
const int mod = 1e9+7;
public:
	int distinctSubsequences(string s, string t) {
		int n = s.size();
		int m = t.size();
		vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
		for(int i = 0; i<=n; i++){
			dp[i][0] = 1;
		}
		for(int i = 1; i<=m; i++){
			dp[0][i] = 0;
		}
		for(int i = 1; i<=n; i++){
			for(int j =1; j<=m; j++){
				if(s[i-1] == t[j-1]){
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[n][m];
	}
};

int main() {
	string s, t;
	cout << "Enter string s: ";
	cin >> s;
	cout << "Enter string t: ";
	cin >> t;
	Solution sol;
	int result = sol.distinctSubsequences(s, t);
	cout << "Number of distinct subsequences: " << result << endl;
	return 0;
}
