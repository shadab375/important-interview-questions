#include <bits/stdc++.h>
using namespace std;

//RECURSION + MEMOIZATION

class Solution {
public:

    int f(int i, int k, vector<int>& arr, vector<int>& dp) {
        int n = arr.size();
        if (dp[i] != -1) return dp[i];

        if (i == n) return 0;
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        for (int j=i; j<min(n, k+i); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int ans = len*maxi + f(j+1, k, arr, dp);
            maxAns = max(maxAns, ans);
        }
        return dp[i] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, k, arr, dp);   
    }
};

//TABULATION

class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for (int i=n-1; i>=0; i--) {
            int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
            for (int j=i; j<min(n, k+i); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int ans = len*maxi + dp[j+1];
                maxAns = max(maxAns, ans);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};