// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *

#include <iostream>

using namespace std;

int main() {
    
    int r = 5;
    int c = 5;
    int intial_space = r - 1;
    int opposite_r = r - 1;
    
    // upper part
    for (int i = 1; i <= r; i++){
        
        for (int j=1; j<=i; j++){
            cout << "*";
        }
        
        for (int k = 1 ; k <= intial_space; k++){
            cout << " ";
        }
        
        for (int k = 1 ; k <= intial_space; k++){
            cout << " ";
        }
        
        for (int l=1; l<=i; l++){
            cout << "*";
        }
        
        intial_space=intial_space-1;
        cout << endl;
    }
    
    // lower part
    intial_space = 2;
    for (int i = opposite_r; i >=0 ; i--){
        
        for (int j = 1 ; j <= i; j++){
            cout << "*";
        }
        
        for (int k = 1; k <= intial_space; k++){
            cout << " ";
        }
        
        for (int j = 1 ; j <= i; j++){
            cout << "*";
        }
        
        intial_space = intial_space + 2;
        cout << endl;
    }
    
}