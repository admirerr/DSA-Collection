//C++ program to find the LCM using the HCF of the numbers
//This algorithm finds LCM of two numbers in logarithmic time complexity
#include <bits/stdc++.h>
using namespace std;
// Function to compute the HCF, to further use in finding the LCM

int Find_HCF(int a, int b){
    while(a>0 && b>0){
        // If a > b then a%b
        if(a>b){
            a = a%b;
        }
        // Else b%a
        else{
            b = b%a;
        }
    }
    // When the loop exhausts, the non zero number will be the HCF
    if(a==0){
        return b;
    }
    else{
        return a;
    }
}
int Find_LCM(int a, int b){
    //Using the formula lcm=a*b/hcf(a,b),
    return a*b/Find_HCF(a,b);
}

int main(){
    // Input two numbers
    int a,b;
    cin >> a >> b;
    // Calling Find_LCM function to find the LCM,
    cout << Find_LCM(a,b) ;
}


//Time Complexity = O(log(min(a,b)))
//Space Complexity = O(1)
