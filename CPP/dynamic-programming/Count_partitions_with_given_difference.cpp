#include <bits/stdc++.h>
using namespace std;

class Solution {
  int mod = (int)1e9 + 7;
private:
  int func(vector<int>&arr, int target, int n){
    vector<int>prev(target+1,0), curr(target+1, 0);
    if(arr[0] == 0)
      prev[0] = 2;
    else
      prev[0] = 1;
    if(arr[0] != 0 && arr[0]<= target)
      prev[arr[0]] = 1;
    for(int i = 1; i<n; i++){
      for(int tar = 0; tar<= target; tar++){
        int nottaken = prev[tar];
        int take = 0;
        if(arr[i]<=tar)
          take = prev[tar - arr[i]];
        curr[tar] = (nottaken + take)%mod;
      }
      prev = curr;
    }
    return prev[target];
  }
public:
   int countPartitions(int n, int diff, vector<int>& arr) {
      int sum = 0;
      for(int i = 0; i<n; i++)sum+=arr[i];
      if(sum-diff <0 || (sum-diff)%2)return 0;
      return func(arr, (sum-diff)/2, n);
    }
};

int main() {
    int n, diff;
    cout << "Enter number of elements and difference: ";
    cin >> n >> diff;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; ++i) cin >> arr[i];
    Solution sol;
    int result = sol.countPartitions(n, diff, arr);
    cout << "Number of partitions: " << result << endl;
    return 0;
}
