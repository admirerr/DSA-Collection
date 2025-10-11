#include <iostream>
#include <vector>

using namespace std; 

void subseq(vector<int> &ans, vector<int> &arr, int index, int size, int k , int sum){
   
   if (index >= size){
       if(sum == k){
           for(auto i : ans){
               cout << i << " ";
           }
           cout << endl;
       }
       return;
   }
   
   // take it
   ans.push_back(arr[index]);
   sum+=arr[index];
   
   subseq(ans,arr,index+1,size,k,sum);
   
   // after take it remove it (backtrack)
   ans.erase(ans.begin()+index);
   sum-=arr[index];
   subseq(ans,arr,index+1,size,k,sum);
}

int main() {
    
    vector<int> arr = {3,1,2};
    vector<int> ans = {};
    int k = 3;
    
    subseq(ans,arr,0,arr.size(),k,0);
    
    return 0;
}