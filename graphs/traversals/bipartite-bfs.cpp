#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(int source, vector<int>& color, vector<vector<int>>& adj) {
        color[source] = 0;
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &adjNode: adj[node]) {
                if (color[adjNode] == -1) {
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                else if (color[adjNode] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);

        for (int i=0; i<V; i++) {
            if (color[i] == -1) {
                if (bfs(i, color, adj) == false) return false;
            }
        }

        return true;
    }
};