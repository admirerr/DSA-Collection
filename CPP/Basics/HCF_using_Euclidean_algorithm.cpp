//C++ program to compute HCF/GCD of two numbers using Euclidean algorithm
//This algorithm finds HCF of two numbers in logarithmic time complexity

#include <bits/stdc++.h>
using namespace std;

// Function to compute HCF/GCD

int Compute_HCF(int a, int b){
    // Loop as long as both the numbers are greater than zero
    while(a>0 && b>0){
        // If a is greater than b then modularise a with b
        if(a>b){
            a = a%b;
        }
        // Otherwise modularise b with a
        else{
            b = b%a;
        }
    }
    // After the termination of loop, the non zero number will be the HCF/GCD
    if(a==0) return b;
    return a;
}


int main(){
    // Input two numbers
    int a,b;
    cin >> a >> b;
    // Call Compute_HCF function to evaluate HCF
    cout << Compute_HCF(a,b) ;
}

/*
Time complexity = O(log(min(a,b)))
Space complexity = O(1)
*/
