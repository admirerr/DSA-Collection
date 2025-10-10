#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weights, vector<bool> &visited, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void prims(vector<vector<int>> &graph, int n) {
    vector<int> parent(n, -1);
    vector<int> weights(n, INT_MAX);
    vector<bool> visited(n, false);
    weights[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++) {
            if (graph[minVertex][j] != 0 && !visited[j] && graph[minVertex][j] < weights[j]) {
                weights[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }

    cout << "Edge  Weight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << "  " << graph[i][parent[i]] << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph, n);
    return 0;
}
