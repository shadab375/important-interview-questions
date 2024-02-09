class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int x, int y, int n, int m, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[x][y] = true;

        for (auto &dir: directions) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];

            auto isSafe = [&](int x, int y) {
                return x >= 0 && x < n && y >= 0 && y < m;
            };

            if (isSafe(new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y] == '1') {
                dfs(new_x, new_y, n, m, visited, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, n, m, visited, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
