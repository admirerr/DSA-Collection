// It shows an alternate number and alphabet pattern printing with n being the number of rows.//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    // n being the number of rows//
    cout << "The number of rows:";
    cin >> n;
    // user will input the value of n.//
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 != 0)
            {
                cout << j; // It will print numbers in the odd row.//
            }
            else
            {
                cout << char(j + 64); // It will print alphabets in the even row.//
            }
        }
        cout << endl; // leave a line after second for loop.//
    }
}