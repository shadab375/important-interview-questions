//recursion + memoization

class Solution {
public:

    int f(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        int n = triangle.size();
        if (i == n-1) return triangle[n-1][j]; //base case
        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(triangle, i+1, j, dp);
        int diag = triangle[i][j] + f(triangle, i+1, j+1, dp);

        return dp[i][j] = min(down, diag);




    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(triangle, 0, 0, dp);
    }
};

//tabulation

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];  //base case
        }

        for (int i=n-2; i>=0; i--){
            for (int j=i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }

        }

        return dp[0][0];


    }
};

//space optimization

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);

        for (int j=0; j<n; j++){
            front[j] = triangle[n-1][j];  //base case
        }

        for (int i=n-2; i>=0; i--){
            vector<int> cur(n, 0);
            for (int j=i; j>=0; j--){
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                cur[j] = min(down, diag);
            }
            front = cur;

        }

        return front[0];


    }
};