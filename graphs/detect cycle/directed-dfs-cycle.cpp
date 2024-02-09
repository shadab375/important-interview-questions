//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCycleDFS(int u, vector<int> adj[], vector<int>& visited, vector<int>& inRecursion) {
        visited[u] = 1;
        inRecursion[u] = 1;
        
        for (int &v: adj[u]) {
            if (!visited[v]) {
                if (isCycleDFS(v, adj, visited, inRecursion)) return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }
        
        inRecursion[u] = 0;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> inRecursion(V, 0);
        
        for (int i=0; i<V; i++) {
            if (!visited[i] && isCycleDFS(i, adj, visited, inRecursion)) {
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends