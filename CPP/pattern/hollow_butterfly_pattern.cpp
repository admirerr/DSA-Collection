// *        *
// **      **
// * *    * *
// *  *  *  *
// *   **   *
// *   **   *
// *  *  *  *
// * *    * *
// **      **
// *        *


#include <iostream>
using namespace std;

int main() {
    // change r to change butterfly size
    int r = 5;                      // try r = 3, 6, 8 to see different butterfly sizes.
    int initial_space = r - 1;

    // upper half
    for (int i = 1; i <= r; i++) {
        // left wing
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        // middle gap
        for (int k = 1; k <= initial_space * 2; k++) cout << " ";

        // right wing 
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        cout << endl;
        initial_space--;
    }

    // lower half [mirror of upper]
    initial_space = 0;
    for (int i = r; i >= 1; i--) {
        // left wing
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        // middle gap
        for (int k = 1; k <= initial_space * 2; k++) cout << " ";

        // right wing 
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) cout << "*";
            else cout << " ";
        }

        cout << endl;
        initial_space++;
    }

    return 0;
}