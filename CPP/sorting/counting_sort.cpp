#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> cnt(mx + 1, 0);
    for (int x : arr) cnt[x]++;
    int idx = 0;
    for (int i = 0; i <= mx; i++) {
        while (cnt[i]--) arr[idx++] = i;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    counting_sort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
}
