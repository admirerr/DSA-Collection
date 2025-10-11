/****************************************
Problem: Topological Sorting of a Directed Acyclic Graph (DAG)

Description:
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, 
find any valid topological ordering of the graph. In a topological 
ordering, for every directed edge u -> v, node u will always appear 
before node v in the ordering. 

This ordering is useful in scenarios such as task scheduling, 
course prerequisite resolution, and resolving symbol dependencies 
in compilers.

Time Complexity: O(V + E) - each vertex and edge is processed once
Space Complexity: O(V + E) - adjacency list, in-degree array/stack/queue, and output list
****************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
// Helper function to perform DFS and push nodes into stack
	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1; // Mark node as visited

		for (auto it : adj[node]) {  // Visit all unvisited neighbors
			if (!vis[it]) dfs(it, vis, st, adj);
		}

        // Once all neighbors are processed, push current node
		st.push(node);
	}
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;

        // Run DFS from every unvisited node
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

        // Extract nodes from stack to get topological order
		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};


int main() {

    // Example graph:
    // V = 6
    // Edges: 2 -> 3, 3 -> 1, 4 -> 0, 4 -> 1, 5 -> 0, 5 -> 2
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);
    cout<<"Topological sorting: ";
	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}

/****************************************
Expected Output for the test case:

Topological Sorting: 5 4 2 3 1 0 

(Note: For topological sort, multiple valid outputs are possible.
For example, "4 5 2 3 1 0" is also valid.)
****************************************/