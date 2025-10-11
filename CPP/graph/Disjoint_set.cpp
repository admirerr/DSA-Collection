/*
A Disjoint Set Union (DSU) or Union-Find is a data structure used to manage a collection of non-overlapping sets. It efficiently supports two main operations — find, 
which identifies the representative (or parent) of a set an element belongs to, and union, which merges two different sets. With optimizations like path compression 
(flattening the structure) and union by rank/size (keeping trees shallow), DSU achieves near-constant time performance for these operations. It is widely used in 
problems involving connected components, such as Kruskal’s algorithm for Minimum Spanning Tree, network connectivity, and dynamic grouping.

The code defines a DisjointSet class that implements DSU using both rank and size methods for efficient merging. The constructor initializes parent, rank, and size 
arrays for all elements. The findUPar() method applies path compression to speed up repeated lookups, while unionByRank() and unionBySize() combine sets based on 
tree height or size, respectively. In the main() function, several unions are performed to group nodes, and then the program checks whether two nodes (3 and 7) are 
in the same set before and after additional unions, demonstrating the functionality of DSU in connecting components.
*/

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}

/*
Output:
Not Same
Same

Time Complexity:  The time complexity is O(4) which is very small and close to 1. So, we can consider 4 as a constant.
*/
