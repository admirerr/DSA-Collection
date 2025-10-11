#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
 * Problem: Minimum Spanning Tree using Prim's Algorithm
 * Author: Your Name
 * Language: C++
 * Description:
 * Prim's algorithm is a greedy algorithm to find the Minimum Spanning Tree (MST) 
 * of a connected, undirected, and weighted graph. It starts from a vertex and 
 * repeatedly adds the minimum weight edge that connects a visited vertex to an unvisited vertex.
 * 
 * Input:
 * - Number of vertices (n) and edges (m)
 * - Each edge as: u v weight
 * 
 * Output:
 * - Total weight of the MST
 * 
 * Time Complexity: O(E log V) using priority queue, where V is vertices, E is edges
 * Space Complexity: O(V + E)
 */



typedef pair<int, int> pii;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    int total_weight = 0;
    vector<pii> mst_edges;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total_weight += w;

        for (auto &[weight, v] : adj[u]) {
            if (!visited[v]) pq.push({weight, v});
        }
    }

    cout << "Total weight of MST: " << total_weight << endl;
    return 0;
}
