// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

bool canGo(int row, int col, vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Check boundaries and validity
    if (row < 0 || col < 0 || row >= n || col >= n) return false;
    if (matrix[row][col] == 0 || matrix[row][col] == -1) return false;

    return true;
}

void solveMaze(int row, int col, vector<vector<int>>& matrix, string& part, int size, vector<string>& ans){

    if (row == size-1 && col == size-1){
        ans.push_back(part);
        return;
    }

    // mark cell as visited
    matrix[row][col] = -1;

    // check down
    if (canGo(row+1,col,matrix)){
        part = part + "D";
        solveMaze(row+1,col,matrix,part,size,ans);
        part.pop_back();
    }

    // check up
    if (canGo(row-1,col,matrix)){
        part = part + "U";
        solveMaze(row-1,col,matrix,part,size,ans);
        part.pop_back();
    }

    // check left
    if(canGo(row,col-1,matrix)){
        part = part + "L";
        solveMaze(row,col-1,matrix,part,size,ans);
        part.pop_back();
    }

    // check right
    if(canGo(row,col+1,matrix)){
        part = part + "R";
        solveMaze(row,col+1,matrix,part,size,ans);
        part.pop_back();
    }

    // unmark
    matrix[row][col] = 1;
}

int main() {

    vector<vector<int>> matrix = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> ans;
    string part= "";

    solveMaze(0,0,matrix,part,matrix.size(),ans);

    for (auto i : ans){
        cout << i << " ";
    }

    return 0;
}