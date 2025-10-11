#include <bits/stdc++.h>
using namespace std;

int main(){

    // print all divisions
    int num = 36;
    vector <int> nums;
    
    for (int i = 1 ; i <= sqrt(num); i++){
        if(num%i == 0){
            nums.emplace_back(i);
            if (num / i != i){ // for preventing double 6 
                nums.emplace_back(num/i);
            }
        }
    }
    
    sort(nums.begin(),nums.end());
    
    for (auto i : nums){
        cout << i << " ";
    }
    
    // 1 2 3 4 6 9 12 18 36 
	
	return 0;
}