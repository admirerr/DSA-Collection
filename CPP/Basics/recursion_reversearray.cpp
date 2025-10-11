#include <iostream>
#include <vector>

using namespace std;

// Recursion -> Reverse Array using 2 pointers

// &arr means alias if main's arr
void reverse(vector<int> &arr , int start , int end){

    // if both are same / start > end then return
    if (start >= end){
        return;
    }

    // swap logic 
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // recursive call
    reverse(arr,start+1,end-1);
}

int main() {
    
    vector<int> arr = {1,2,3,4,5};
    
    cout << "Before" << endl;
    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    
    // calling function 
    reverse(arr,0,arr.size()-1);
    
    cout << "After" << endl;
    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}