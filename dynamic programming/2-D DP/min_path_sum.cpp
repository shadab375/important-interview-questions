//recursion + memoization

class Solution {
public:

    int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if (i<0 || j<0) return 1e9;
        if (i==0 && j==0) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + f(grid, i-1, j, dp);
        int left = grid[i][j] + f(grid, i, j-1, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp (n, vector<int>(m, -1));
        return f(grid, n-1, m-1, dp);
    }
};

//tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp (n, vector<int>(m, 0));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (i==0 && j==0){
                     dp[i][j] = grid[i][j];
                }
                else{
                    int up = grid[i][j] + ((i - 1 >= 0) ? dp[i-1][j] : 1e9);
                    int left = grid[i][j] + ((j - 1 >= 0) ? dp[i][j-1] : 1e9);
                    dp[i][j] = min(up, left);
                }
            }
        
        }
        return dp[n-1][m-1];
    }
};

//space optimization

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 0);

        for (int i=0; i<n; i++){
            vector<int> cur(m, 0);
            for (int j=0; j<m; j++){
                if (i==0 && j==0){
                     cur[j] = grid[i][j];
                }
                else{
                    int up = grid[i][j] + ((i - 1 >= 0) ? prev[j] : 1e9);
                    int left = grid[i][j] + ((j - 1 >= 0) ? cur[j-1] : 1e9);
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[m-1];
    }
};

