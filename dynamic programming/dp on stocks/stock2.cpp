//recursion + memoization
class Solution {
public:

    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if (ind == n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy){               //we have option of buying
            profit = max(-prices[ind] + f(ind+1, 0, prices, dp),
                                        0 + f(ind+1, 1, prices, dp));
        }
        else{                   //we have option of selling
            profit = max(prices[ind] + f(ind+1, 1, prices, dp),
                                      0 + f(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

//tabulation
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <=1; buy++){
                int profit = 0;
                if (buy){               //we have option of buying
                    profit = max(-prices[ind] + dp[ind+1][0],
                                  0 + dp[ind+1][1]);
                }
                else{                   //we have option of selling
                    profit = max(prices[ind] + dp[ind+1][1],
                                  0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//space optimization
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);
        ahead[0] = ahead[1] = 0;

        for (int ind = n-1; ind >= 0; ind--){
            for (int buy = 0; buy <=1; buy++){
                int profit = 0;
                if (buy){               //we have option of buying
                    profit = max(-prices[ind] + ahead[0],
                                  0 + ahead[1]);
                }
                else{                   //we have option of selling
                    profit = max(prices[ind] + ahead[1],
                                  0 + ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
};

//4 variables approach
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;

        for (int ind = n-1; ind >= 0; ind--){
            curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);
            curNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};