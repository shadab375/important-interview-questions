//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis) {
        vis[node] = true;
        pathvis[node] = true;
        
        for (auto &adjNode: adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, adj, vis, pathvis) == true) return true;
                
            }
            else if (pathvis[adjNode] == true) return true;
        }
        
        pathvis[node] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), pathvis(V, 0);
        
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis) == true) return true;
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