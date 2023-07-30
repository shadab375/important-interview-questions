//RECURSION + MEMOIZATION

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if(ind == 0){
        return (W/wt[0]) * val[0];
    }
    if (dp[ind][W] != -1) return dp[ind][W];

    int notTake = 0 + f(ind-1, W, wt, val, dp);
    int take = -1e9;
    if (wt[ind] <= W) take = val[ind] + f(ind, W-wt[ind], wt, val, dp);

    return dp[ind][W] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, wt, val, dp);
}

//TABULATION

#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for (int W=0; W<=w; W++) dp[0][W] = (W/wt[0]) * val[0];

    for (int ind=1; ind<n; ind++) {
        for (int W=0; W<=w; W++) {
            int notTake = 0 + dp[ind-1][W];
            int take = -1e9;
            if (wt[ind] <= W) take = val[ind] + dp[ind][W-wt[ind]];
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n-1][w];
}