#include <iostream>
#include <vector>
#include <climits>   // For INT_MAX
using namespace std;

int findMinVertex(vector<int>& key, vector<bool>& inMST, int n) {
    int minKey = INT_MAX;
    int vertex = -1;

    for (int i = 0; i < n; i++) {
        if (!inMST[i] && key[i] < minKey) {
            minKey = key[i];
            vertex = i;
        }
    }
    return vertex;
}

void primsAlgorithm(vector<vector<int>>& graph, int n) {
    vector<int> parent(n, -1);      // To store MST structure
    vector<int> key(n, INT_MAX);    // To store minimum edge weight
    vector<bool> inMST(n, false);   // To check if vertex is included in MST

    key[0] = 0;  // Start from the first vertex

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(key, inMST, n);
        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the resulting Minimum Spanning Tree
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    primsAlgorithm(graph, n);

    return 0;
}
