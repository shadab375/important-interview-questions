class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& visited) {
        visited[u] = 1;

        for (int &v: adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);

        for (auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(source, adj, visited);
        if (visited[destination] == 0) return false;
        return true;
    }
};