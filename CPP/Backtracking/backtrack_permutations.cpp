#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void recursion(vector<vector<int>>& ans, vector<int>& oneAns, vector<int> &nums, int size){
        if (nums.empty()){
            ans.push_back(oneAns);
            return;
        }   

        for (int i = 0; i < nums.size(); i++){
            oneAns.push_back(nums[i]); // selects first

            vector<int> tempNums(nums.begin(),nums.end());
            // its erase only that index element (it takes iterator object)
            tempNums.erase(tempNums.begin()+i);
            
            recursion(ans,oneAns,tempNums,size);
            
            // after done remove the added element on that specific loop 
            oneAns.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> oneAns;

        recursion(ans,oneAns,nums,nums.size());

        return ans;
    }
};

int main(){

    vector<int> nums = {1,2,3};

    Solution s;
    vector<vector<int>> ans = s.permute(nums);

    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}