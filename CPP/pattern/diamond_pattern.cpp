//    * 
//   ***
//  ***** 
// ******* 
//********* 
// ******* 
//  *****
//   ***
//    * 

#include <iostream>

using namespace std;

int main() {
    
    int r = 4;
    int c = 5;
    int space;
    int star;
    int opposite_r = r - 1;
    
    for (int i = 0 ; i < r ; i++){
        space = r - i - 1;
        for (int j = 0; j < space ; j++){
            cout << " ";
        }
        
        star = (2*i) + 1;
        for (int k = 0 ; k < star ; k++){
            cout << "*";
        }
        
        cout << endl;
    }
    
    for (int i = opposite_r - 1; i >= 0 ; i--){
        space = opposite_r - i;
        for (int j = 0 ; j < space; j++){
            cout << " ";
        }
        
        star = (2*i) + 1;
        for(int k = 0 ; k < star ; k++){
            cout << "*";
        }
        
        cout << endl;
    }

    return 0;
}