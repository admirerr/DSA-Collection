#include <iostream>
#include <vector>
#include <climits>

int findMinVertex(const std::vector<int>& key, const std::vector<bool>& inMST, int n) {
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

void primsAlgorithm(const std::vector<std::vector<int>>& graph, int n) {
    std::vector<int> parent(n, -1);
    std::vector<int> key(n, INT_MAX);
    std::vector<bool> inMST(n, false);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(key, inMST, n);
        if (u == -1) break;
        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            std::cout << parent[i] << " " << i << " " << graph[i][parent[i]] << "\n";
        }
    }
}

int main() {
    int n;
    if (!(std::cin >> n)) {
        return 0; // Handle invalid input gracefully
    }

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    primsAlgorithm(graph, n);
    return 0;
}
