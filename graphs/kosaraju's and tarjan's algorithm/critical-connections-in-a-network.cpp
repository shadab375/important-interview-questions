#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int timer = 0;
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<vector<int>>& bridges) {
        low[u] = disc[u] = timer;
        timer++;

        for (auto &v: adj[u]) {
            if (disc[v] == -1) {
                dfs(v, u, adj, disc, low, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) bridges.push_back({v, u});
            }
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    } 

    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections) {
        vector<vector<int>> adj(V);
        vector<vector<int>> bridges;
        vector<int> low(V, -1), disc(V, -1);

        for (auto &it: connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i=0; i<V; i++) {
            if (disc[i] == -1) dfs(i, -1, adj, disc, low, bridges);
        }

        return bridges;
    }
};