/****************************************
* Problem: Trapping Rain Water
*
* Description:
* Calculates the total amount of rainwater that can be trapped 
* between bars of varying heights after raining. The algorithm 
* uses a two-pointer approach that efficiently computes trapped 
* water by maintaining the maximum heights seen from both ends 
* and moving inward.
*
* Approach:
* - Initialize two pointers (left and right) at both ends.
* - Track the maximum height on the left and right sides.
* - Move the pointer with the smaller height inward.
* - At each step, calculate trapped water based on the difference 
*   between the current height and the maximum height on that side.
*
* Time Complexity: O(n) - single traversal using two pointers
* Space Complexity: O(1) - constant extra space

* Sample Output:
* Trapped Rainwater: 6
*
* Explanation:
* Bars at positions 2, 4, 5, 6, 9, and 10 trap water.
* The total trapped water is 6 units.
****************************************/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate total trapped rainwater
int calculateTrappedWater(vector<int>& heights) {
    int n = heights.size();
    int leftIndex = 0, rightIndex = n - 1; 
    int totalWater = 0; // Variable to store total trapped water
    int leftMax = 0, rightMax = 0; // Variables to store maximum height encountered from left and right sides

    while (leftIndex <= rightIndex) {
        
        // Compare the current heights to decide which pointer to move
        if (heights[leftIndex] <= heights[rightIndex]) {
            if (heights[leftIndex] >= leftMax)
                leftMax = heights[leftIndex];
            else
                totalWater += leftMax - heights[leftIndex];

            leftIndex++;
        } else {
            if (heights[rightIndex] >= rightMax)
                rightMax = heights[rightIndex];
            else
                totalWater += rightMax - heights[rightIndex];

            rightIndex--;
        }
    }

    return totalWater;
}

int main() {
    vector<int> elevationMap = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Trapped Rainwater: " << calculateTrappedWater(elevationMap) << endl;

    return 0;
}
