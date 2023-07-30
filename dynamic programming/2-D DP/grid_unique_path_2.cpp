//recursion + memoization

class Solution {

    int f(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();


        if (i<0 || j<0) return 0;
        if (i>=0 && j>=0 && obstacleGrid[i][j] == 1) return 0;
        if (i==0 && j==0) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int up = obstacleGrid[i][j] + f(obstacleGrid, i-1, j, dp);
        int left = obstacleGrid[i][j] + f(obstacleGrid, i, j-1, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(obstacleGrid, n-1, m-1, dp);
    }
};

//tabulation

class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (i==0 && j==0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if (i-1 >= 0) up = dp[i-1][j];
                    if (j-1 >= 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//space optimization 

class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m, 0);
        
        for (int i=0; i<n; i++){
            vector<int> cur(m, 0);
            for (int j=0; j<m; j++){
                if (obstacleGrid[i][j] == 1) cur[j] = 0;
                else if (i==0 && j==0) cur[j] = 1;
                else{
                    int up = 0, left = 0;
                    if (i-1 >= 0) up = prev[j];
                    if (j-1 >= 0) left = cur[j-1];
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        return prev[m-1];
    }
};