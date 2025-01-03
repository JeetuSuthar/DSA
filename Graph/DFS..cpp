LINK-> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int start, vector<vector<int>>& adj, int visited[], vector<int>& ans) {
        visited[start] = 1;
        ans.push_back(start);
        
        for (auto it : adj[start]) {
            if (!visited[it]) {
                dfs(it, adj, visited, ans);
            }
        }
    }
    
public:
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();
        int visited[V] = {0}; // To keep track of visited vertices
        
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) { // If the node is not visited
                dfs(i, adj, visited, ans);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example graph represented as an adjacency list
    vector<vector<int>> adj = {
        {1, 2},      // Node 0 is connected to node 1 and 2
        {0, 3, 4},   // Node 1 is connected to node 0, 3, and 4
        {0},         // Node 2 is connected to node 0
        {1},         // Node 3 is connected to node 1
        {1}          // Node 4 is connected to node 1
    };
    
    // Get the DFS traversal of the graph
    vector<int> result = solution.dfsOfGraph(adj);
    
    // Print the result
    for (int node : result) {
        cout << node << " ";
    }
    
    return 0;
}
