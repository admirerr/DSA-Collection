#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, sum = 0, temp, digits = 0;
    cin >> num;
    temp = num;
    int x = num;
    while (x != 0)
    {
        digits++;
        x = x / 10;
    }
    temp = num;
    while (temp != 0)
    {
        int r = temp % 10;
        sum += pow(r, digits);
        temp /= 10;
    }
    if (sum == num)
        cout << "Armstrong Number";
    else
        cout << "Not Armstrong Number";
    return 0;
}
