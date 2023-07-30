#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i=1; i<n; i++){
            int take = nums[i] + prev2;
            int non_take = 0 + prev;

            int curi = max(take, non_take);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i=1; i<n; i++){
            int take = nums[i] + ((i-2 >= 0) ? dp[i-2] : 0);
            int non_take = 0 + dp[i-1];
            dp[i] = max(take, non_take);
        }
        return dp[n-1];
    }
};

class Solution {
public:

    int f(int ind, vector<int>& nums, vector<int>& dp){
        if (ind == 0) return nums[0];
        if (ind < 0) return 0;  
        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + f(ind-2, nums, dp);
        int non_pick = 0 + f(ind-1, nums, dp);

        return dp[ind] = max(pick, non_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
        
    }
};