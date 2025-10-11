#include <iostream>
#include <vector>
using namespace std;

// Function to perform cyclic sort
void cyclicSort(vector<int> &arr) {
    int i = 0;
    while (i < arr.size()) {
        int correctIndex = arr[i] - 1;  // correct index for current element
        if (arr[i] != arr[correctIndex]) {
            // swap if current element is not at the correct position
            swap(arr[i], arr[correctIndex]);
        } else {
            i++;  // move to next index
        }
    }
}

int main() {
    // Example input
    vector<int> arr = {3, 5, 2, 1, 4};

    cout << "Before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cyclicSort(arr);

    cout << "After sorting:  ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
