class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, int target, vector<vector<int>>& ans, vector<int>& temp) {
        temp.push_back(u);
        if (u == target) {
            ans.push_back(temp);
        } else {
            for (int &v: adj[u]) {
                dfs(v, adj, target, ans, temp);
            }
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> ans;
        vector<int> temp;

        int source = 0, target = n - 1;

        dfs(source, adj, target, ans, temp);
        return ans;
    }
};