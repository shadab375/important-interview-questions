#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        color[node] = col;

        for (auto &adjNode: adj[node]) {
            if (color[adjNode] == -1) {
                if (dfs(adjNode, !col, color, adj) == false) return false;
            }
            else if (color[adjNode] == col) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);

        for (int i=0; i<V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) return false;
            }
        }

        return true;
    }
};