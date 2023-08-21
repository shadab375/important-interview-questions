class Solution {
public:

    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = true;

        for (auto &adjNode: adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size();
        int m = adjMatrix[0].size();
        vector<int> vis(n, 0);
        vector<int> adj[n];

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (adjMatrix[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                count++;
            }
        }

        return count;
    }
};