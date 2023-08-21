#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);

        for (int u=0; u<V; u++) {
            for (auto &v: adj[u]) {
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto &adjNode: adjRev[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) q.push(adjNode);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};