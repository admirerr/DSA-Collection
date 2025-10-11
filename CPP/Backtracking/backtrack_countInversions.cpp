#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int i = l, j = m + 1;
    vector<int> temp;
    long long cnt = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            cnt += (m - i + 1); // inversion count
        }
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    // copy back
    for (int k = l; k <= r; k++) arr[k] = temp[k - l];

    return cnt;
}

long long countInversion(vector<int>& arr, int l, int r) {
    long long cnt = 0;
    if (l < r) {
        int m = (l + r) / 2;
        cnt += countInversion(arr, l, m);
        cnt += countInversion(arr, m + 1, r);
        cnt += mergeAndCount(arr, l, m, r);
    }
    return cnt;
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << "Inversions: " << countInversion(arr, 0, arr.size() - 1);
    return 0;
}