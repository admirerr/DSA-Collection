// C++ program to reverse a number
// This program works for non-negative integers only

#include<bits/stdc++.h>
using namespace std;
int main()
{
 int num;
 long long int rev_num;

  // num variable stores the number given by the user
  // rev_num variable stores the reversed number
cout<<"Enter a number to reverse: ";
cin>>num;

// if the number is 0, then the reversed number is also 0
if(num==0){
 cout<<"The reversed number is: 0"<<endl;
 return 0;
 }

rev_num=0;

  // loop to reverse the number
while(num>0)
{
 // extracts the last digit of the number
 int digit=num%10;

 // appends the digit to the reversed number
 rev_num=rev_num*10+digit;
 // removes the last digit from the number
 num=num/10;
}

// prints the reversed number
cout<<"The reversed number is: "<<rev_num<<endl;
return 0;
}