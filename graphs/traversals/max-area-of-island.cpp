class Solution {
public:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& grid, int x, int y, int n, int m, int &area) {
        area++;
        grid[x][y] = 0;

        for (auto &dir: directions) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];

            auto isSafe = [&](int x, int y) {
                return x >= 0 && x < n && y >=0 && y < m;
            };

            if (isSafe(new_x, new_y) && grid[new_x][new_y] == 1) {
                dfs(grid, new_x, new_y, n, m, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, n, m, area);
                    ans = max(ans, area);
                }
            }
        }   

        return ans;
    }
};