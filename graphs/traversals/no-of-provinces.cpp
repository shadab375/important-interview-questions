class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<int>& visited) {
        visited[u] = 1;

        for (auto &v: adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adjMatrix) {
        int V = adjMatrix.size();
        vector<int> visited(V, 0);
        vector<int> adj[V];

        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (adjMatrix[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};