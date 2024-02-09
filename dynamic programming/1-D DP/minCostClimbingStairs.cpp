class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev = cost[1];
        int prev2 = cost[0];

        for (int i=2; i<n; i++){
            int curi = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = curi;
        }
        return min(prev, prev2);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i=2; i<n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};

class Solution {
public:
    int f(int i, int n, vector<int>& cost, vector<int>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int one_step = cost[i] + f(i+1, n, cost,dp);
        int two_step = cost[i] + f(i+2, n, cost, dp);

        return dp[i] = min(one_step, two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(f(0, n, cost, dp), f(1, n, cost, dp));
    }
};