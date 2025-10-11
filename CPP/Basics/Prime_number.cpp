//C++ Program to check whether a number is prime or not

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    bool is_not_prime;

    // Initialize the is_not_prime variable as false
    is_not_prime = false;

    // Input a non negative integer from user
    cout << "Enter a non negative integer: ";
    cin >> num;

    // 0 and 1 are not prime numbers
    if (num == 0 || num == 1)
        is_not_prime = true;

    // Check from 2 to the square root of number
    // If the number is divisible by any of these numbers, it is not prime    
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            is_not_prime = true;
            break;
        }
    }

    // Print whether the number is prime or not
    if (is_not_prime == false)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}