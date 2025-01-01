//Link --> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    // Function to return Breadth First Traversal of a given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size(); // Number of nodes in the graph
        vector<int> isVisited(n, 0); // To keep track of visited nodes
        vector<int> bfs; // To store BFS traversal
        queue<int> q; // Queue for BFS

        // Start BFS from node 0 (assuming 0-based indexing)
        q.push(0);
        isVisited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto neighbour : adj[node]) {
                if (!isVisited[neighbour]) {
                    isVisited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return bfs;
    }
};

int main() {
    // Example usage
    int vertices = 5; // Number of vertices
    vector<vector<int>> adj(vertices);

    // Adding edges to the graph (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    Graph g;
    vector<int> bfsResult = g.bfsOfGraph(adj);

    // Print BFS traversal
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }

    return 0;
}
