#include <iostream>
#include <vector>
using namespace std;

// Paste your Solution class here (choose one implementation)
class Solution {
    int mod = 1000000007;
public:
    int perfectSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>prev(k+1, 0);
        vector<int>curr(k+1, 0);
        curr[0] = 1;
        prev[0] = 1;
        if(arr[0]<=k){
            prev[arr[0]] = 1;
        }
        for(int i = 1; i<n; i++){                
            for(int tar = 1; tar<=k; tar++){
                int notTaken = prev[tar];
                int take = 0;
                if(arr[i]<=tar){
                    take = prev[tar-arr[i]] % mod;
                }
                curr[tar] = (notTaken+take) % mod;
            }
            prev = curr;
        }
        return prev[k];
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements and target sum: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; ++i) cin >> arr[i];

    Solution sol;
    int result = sol.perfectSum(arr, k);
    cout << "Number of subsets with sum " << k << ": " << result << endl;
    return 0;
}
