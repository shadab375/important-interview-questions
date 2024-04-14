class Solution {
public:
    int m, n;
    int result;
    int nonObstacles;
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void solve(int i, int j, int count, vector<vector<int>>& grid) {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j] == -1) return;
        if (grid[i][j] == 2) {
            if (count == nonObstacles) result++;
            return;
        }

        grid[i][j] = -1;
        for (auto &dir: directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            solve(ni, nj, count+1, grid);
        }
        grid[i][j] = 0;
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        result = 0;
        nonObstacles = 0;
        int start_x = 0, start_y = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) nonObstacles++;
                if (grid[i][j] == 1) start_x = i, start_y = j;
            }
        }

        nonObstacles += 1;
        solve(start_x, start_y, 0, grid);
        return result;
    }
};