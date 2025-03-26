#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Depth First Search function to perform Topological Sorting
    void dfs(int i, stack<int>& s, vector<int>& vis, vector<vector<int>>& adj) {
        vis[i] = 1; // Mark the current node as visited
        for (auto x : adj[i]) { // Traverse all adjacent nodes
            if (!vis[x]) { // If the node is not visited, call DFS recursively
                dfs(x, s, vis, adj);
            }
        }
        s.push(i); // Push the node onto the stack after exploring all its neighbors
    }

    // Function to return a list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        stack<int> s; // Stack to store the topological order
        vector<int> res; // Result vector to store the final order
        vector<int> vis(adj.size(), 0); // Visited array to track visited nodes

        // Perform DFS for all unvisited nodes
        for (int i = 0; i < adj.size(); i++) {
            if (!vis[i]) {
                dfs(i, s, vis, adj);
            }
        }

        // Retrieve elements from stack to get the correct order
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        return res; // Return the topological order
    }
};

// Main function to test the topological sorting
int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V); // Adjacency list representation of graph

    cout << "Enter edges (from -> to):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v; // Read directed edge from u to v
        adj[u].push_back(v);
    }

    Solution sol;
    vector<int> topoOrder = sol.topologicalSort(adj);

    // Print the topological order
    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
