//recursion + memoziation -> gives TLE
class Solution {
public:
    int solve(int e,int f,vector<vector<int>> &dp){
        if(e==1){
            return f;
        }

        if(f==0 || f==1) return f;

        if(dp[e][f]!=-1) return dp[e][f];

        int mini=INT_MAX;
        for(int i=1;i<=f;++i){
            int Break=solve(e-1,i-1,dp);
            int notBreak=solve(e,f-i,dp);
            int temp=1+max(Break,notBreak);
            mini=min(mini,temp);
        }

        return dp[e][f]=mini;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};

//recursion + memoziation + binary search -> doesn't give TLE
class Solution {
public:

    int solve(int e, int f, vector<vector<int>>& dp){
        if (f==0 || f==1) return f;
        if (e==1) return f;
        if (dp[e][f] != -1) return dp[e][f];

        int l=1, r=f;
        int mini = INT_MAX;
        while (l <= r){
            int mid = l + (r - l) / 2;
            int val1 = solve(e-1, mid-1, dp);
            int val2 = solve(e, f-mid, dp);
            int temp = 1 + max(val1, val2);
            mini = min(mini, temp);

            if (val1 < val2) l = mid + 1;
            else r = mid - 1;
        }
        return dp[e][f] = mini;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};

//tabulation -> gives TLE
class Solution {
public:

    int solve(int e, int f, vector<vector<int>>& dp){ //dp[egg][floor] is used
        for (int i=1; i<=e; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int j=1; j<=f; j++){
            dp[1][j] = j;
        }

        for (int i=2; i<=e; i++){
            for (int j=2; j<=f; j++){
                int mini = 1e9;
                for (int k=1; k<=j; k++){
                    int val1 = dp[i-1][k-1];
                    int val2 = dp[i][j-k];
                    int temp = 1 + max(val1, val2);
                    mini = min(mini, temp);
                    dp[i][j] = mini;
                }
            }
        }
        return dp[e][f];
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp (k+1, vector<int> (n+1, 0));
        return solve(k, n, dp);
    }
};

//tabulation with binary search -> test cases passed
class Solution {
public:

    int solve(int e, int f, vector<vector<int>>& dp){ //dp[egg][floor] is used
        for (int i=1; i<=e; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int j=1; j<=f; j++){
            dp[1][j] = j;
        }

        for (int i=2; i<=e; i++){
            for (int j=2; j<=f; j++){
                int mini = 1e9;
                int l = 1, r = j;
                while (l <= r){
                    int mid = l + (r - l) / 2;
                    int val1 = dp[i-1][mid-1];
                    int val2 = dp[i][j-mid];
                    int temp = 1 + max(val1, val2);
                    mini = min(mini, temp);
                    if (val1 < val2) l = mid + 1;
                    else r = mid - 1;
                }
                dp[i][j] = mini;
            }
        }
        return dp[e][f];
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp (k+1, vector<int> (n+1, 0));
        return solve(k, n, dp);
    }
};

//unique approach -> best in terms of time and space
class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[N+1][K+1]; memset(dp, 0, sizeof dp);
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m-1][k- 1] + dp[m-1][k] + 1;
        }
        return m;
    }
};

