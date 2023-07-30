//recursion + memoization

class Solution {
public:

    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if (j < 0 || j >= matrix[0].size()) return 1e9;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int mini = 1e9;
        for (int j=0; j<m; j++){
            int ans = f(n-1, j, matrix, dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};

//tabulation

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j=0; j<m; j++) dp[0][j] = matrix[0][j]; //base case

        for (int i=1; i<n; i++){       //express every state in for loops
            for (int j=0; j<m; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j] + ((j - 1 >= 0) ? dp[i-1][j-1] : 1e9);
                int rd = matrix[i][j] + ((j + 1 < m) ? dp[i-1][j+1] : 1e9);
                dp[i][j] = min({up, ld, rd});
            }
        }

        int mini = 1e9;
        for (int j=0; j<m; j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};

//space optimization

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0);

        for (int j=0; j<m; j++) prev[j] = matrix[0][j]; //base case

        for (int i=1; i<n; i++){              //express every state in for loops
            vector<int> cur(m, 0);    
            for (int j=0; j<m; j++){
                int up = matrix[i][j] + prev[j];
                int ld = matrix[i][j] + ((j - 1 >= 0) ? prev[j-1] : 1e9);
                int rd = matrix[i][j] + ((j + 1 < m) ? prev[j+1] : 1e9);
                cur[j] = min({up, ld, rd});
            }
            prev = cur;
        }

        int mini = 1e9;
        for (int j=0; j<m; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};