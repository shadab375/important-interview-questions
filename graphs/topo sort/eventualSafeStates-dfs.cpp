#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (auto &adjNode: adj[node]) {
            if (!vis[adjNode] && dfs(adjNode, adj, vis, pathVis) == true) {
                return true;
            }
            else if (pathVis[adjNode]) return true;
        }

        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safeNodes;

        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathVis);
            }
        }

        for (int i=0; i<V; i++) {
            if (pathVis[i] == 0) safeNodes.push_back(i);
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};