#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        vector<int> indegree(V, 0);

        for (auto &it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto &adjNode: adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) q.push(adjNode);
            }
        }

        if (topo.size() == V) return true;
        return false;
    }
};