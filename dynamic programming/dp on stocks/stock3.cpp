//METHOD - 1
//recursion + memoization
class Solution {
public:

    int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if (ind==n || cap==0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit=0;
        if (buy){
            profit = max(-prices[ind] + f(ind+1, 0, cap, prices, dp),
                                 0 + f(ind+1, 1, cap, prices, dp));
        }
        else{
            profit = max(prices[ind] + f(ind+1, 1, cap-1, prices, dp),
                                 0 + f(ind+1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};

//tabulation
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        //ind==n
        for (int buy = 0; buy <= 1; buy++){
            for (int cap = 0; cap <= 2; cap++){
                dp[n][buy][cap] = 0;
            }
        }
        //cap==0
        for (int ind=0; ind<n; ind++){
            for (int buy=0; buy <= 1; buy++){
                dp[ind][buy][0] = 0;
            }
        }

        for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    int profit=0;
                    if (buy){
                        profit = max(-prices[ind] + dp[ind+1][0][cap],
                                      0 + dp[ind+1][1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + dp[ind+1][1][cap-1],
                                      0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

//space optimization
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

        for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    int profit=0;
                    if (buy){
                        profit = max(-prices[ind] + after[0][cap],
                                      0 + after[1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + after[1][cap-1],
                                      0 + after[0][cap]);
                    }
                    cur[buy][cap] = profit;
                }
            }
            after = cur;
        }
        return after[1][2];
    }
};

//METHOD-2

//recursion + memoization
class Solution {
public:

    int f(int ind,int trans,int n,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(ind == n || trans ==4) return 0;
        if(dp[ind][trans] !=-1) return dp[ind][trans];

        int profit = 0;
        if(trans%2==0)
        {
            profit = max(-prices[ind]+f(ind+1,trans+1,n,prices,dp),f(ind+1,trans,n,prices,dp));
        }
        else 
        {
            profit = max(prices[ind]+f(ind+1,trans+1,n,prices,dp),f(ind+1,trans,n,prices,dp));
        }
        return dp[ind][trans] = profit;
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0,0,n,prices,dp);
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        for(int i=0;i<=4;i++) dp[n][i] = 0;
        for(int i=0;i<=n;i++) dp[i][4] = 0;
        
        for(int ind=n-1;ind>=0;ind--){  
            for(int trans = 3;trans >= 0;trans--){
                int profit = 0;
                if(trans % 2 == 0){
                    profit = max(-prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
                }
                else{              
                    profit = max(prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
                }
                dp[ind][trans] = profit;
            }
        }
        return dp[0][0];
    }
};

//space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(5,-1),cur(5,-1);
        for(int i=0;i<=4;i++)
        {
            ahead[i] = 0;
        }
        cur[4]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans = 3;trans>=0;trans--)
            {
                if(trans%2==0)
                {
                    cur[trans] = max(-prices[ind]+ahead[trans+1],ahead[trans]);
                }
                else 
                {
                    cur[trans] = max(prices[ind]+ahead[trans+1],ahead[trans]);
                }
            }
            ahead = cur;
        }
        return ahead[0];
    }
};
