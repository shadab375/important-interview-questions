class Solution
{
public:
    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n + 1, -1);

        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int minCost = INT_MAX;

            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(height[i] - height[i - j]);
                    minCost = min(minCost, jump);
                }
            }
            dp[i] = minCost;
        }
        return dp[n - 1];
    }
};

class Solution
{
public:
    int f(int ind, vector<int> &height, int k, vector<int> &dp)
    {
        if (ind == 0)
        {
            return 0;
        }

        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (ind - j >= 0)
            {
                int jmp = f(ind - j, height, k, dp) + abs(height[ind] - height[ind - j]);
                minCost = min(minCost, jmp);
            }
        }
        return dp[ind] = minCost;
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n, -1);
        return f(n - 1, height, k, dp);
    }


//space optimized soln not required here - as that 