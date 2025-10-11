// This code is written for counting digits of a certain number.//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; // It is that required number.//
    int count = 0;
    cin >> n;
    while (n != 0)
    {
        n = n / 10;
        
            count++;
    }
    cout << count; //It is total number of digits//
}