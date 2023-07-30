class Solution {
public:

    int maximumNumberAdjacentSum(vector<int>& arr){
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;

        for (int i=1; i<n; i++){
            int pick = arr[i] + prev2;
            int non_pick = 0 + prev;

            int curi = max(pick, non_pick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n = nums.size();
        if (n == 1) return nums[0];

        for (int i=0; i<n; i++){
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n-1) temp2.push_back(nums[i]);
        }

        return max(maximumNumberAdjacentSum(temp1), maximumNumberAdjacentSum(temp2));
    }
};

class Solution {
public:
    
    //this function is solution of House robber I. We just use it to solve House Robber II
    int solve(vector<int>& nums, int l, int r) {
        int prev = nums[l];
        int prev2 = 0;

        for (int i=l+1; i<=r; i++){
            int pick = nums[i] + prev2;
            int non_pick = 0 + prev;

            int curi = max(pick, non_pick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        int take_first_house = solve(nums, 0, n-2);
        
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};

class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> dp(n, 0);
        //dp[i] = Max money gained from i houses
        
        int result1 = 0;
        int result2 = 0;
        
        //Case-1 (Take from 1st House - Hence skip the last house)
        dp[0] = nums[0];
        for(int i = 1; i<n-1; i++) {
            int take = nums[i] + ((i-2 >= 0) ? dp[i-2] : 0);
            int non_take = 0 + dp[i-1];
            dp[i] = max(take, non_take);
        }
        result1 = dp[n-2];
        
        dp.clear();
        //Case-2 (Take from 2nd House - Hence take the last house)
        dp[0] = 0;
        for(int i = 1; i<n; i++) {
            int take = nums[i] + ((i-2 >= 0) ? dp[i-2] : 0);
            int non_take = 0 + dp[i-1];
            dp[i] = max(take, non_take);
        }
        result2 = dp[n-1];
        
        return max(result1, result2);
        
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
        vector<int> temp1, temp2;

        int n = nums.size();
        vector<int> dp(n, -1);
        if (n==1) return nums[0];

        for (int i=0; i<n; i++){
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n-1) temp2.push_back(nums[i]);
        }

        int ans1 = f(temp1.size() - 1, temp1, dp);

        fill_n(dp.begin(), n, -1);

        int ans2 = f(temp2.size() - 1, temp2, dp);

        return max(ans1, ans2);
    }
};