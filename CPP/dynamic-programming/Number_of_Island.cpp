#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    DSU dsu(n * m);
    vector<int> dirs = {-1, 0, 0, -1}; // up and left
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                for (int k = 0; k < 2; k++) {
                    int ni = i + dirs[k], nj = j + dirs[k + 2];
                    if (ni >= 0 && nj >= 0 && grid[ni][nj] == '1')
                        dsu.unite(i * m + j, ni * m + nj);
                }
            }
        }
    }

    set<int> islands;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '1')
                islands.insert(dsu.find(i * m + j));

    cout << islands.size() << endl;
}
