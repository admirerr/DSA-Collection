#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int s = 0;
    cout << "enter the no. to be checked";
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            s += i;
    }
    if (s == n)
        cout << "it is a perfect no.";
    else
        cout << "not a perfect no.";
}
