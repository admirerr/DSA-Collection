// This is the code for simple star pattern printing with n rows and m columns.//
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; 
    // n is the number of rows//
    cout << "Enter number of rows:";
    cin >> n; 
    //user will input the value of n//

    int m;
    //m is the number of columns//
    cout << "Enter number of columns:";
    cin >> m;
    //user will input the value of m//

    for (int i = 1; i <= n; i++)  
    {
        for (int j = 1; j <= m; j++)
        {
            cout << "*";
        }
        cout << endl;
         //It is used for changing line once the second for loop is over//
    }
}
