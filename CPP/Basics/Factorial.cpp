// C++ program to find factorial of a number
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking input from user
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    // Factorial can't be calculated for negative numbers
    if(num<0){
        cout<<"Factorial of negative number doesn't exist.";
    }
    else
    {   // Factorial of 0 and 1 is 1
        if(num==0 || num==1){
            cout<<"Factorial of "<<num<<" is 1.";
        }
        else{

            // Factorial calculation
            int fact=1;
            for(int i=2;i<=num;i++){
                fact=fact*i;
            }

            // Displaying the factorial
            cout<<"Factorial of "<<num<<" is "<<fact<<".";
        }
    }
}
        