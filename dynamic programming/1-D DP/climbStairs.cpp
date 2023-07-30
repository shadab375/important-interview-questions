#include<bits/stdc++.h>
using namespace std;


class Solution
{
    int f(int ind, vector<int> &dp)
    {
        if (ind <= 1)
            return 1;
        if (dp[ind] != -1)
            return dp[ind];
        return dp[ind] = f(ind - 1, dp) + f(ind - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev2 = 1, prev = 1;
        int curi;
        for (int i = 2; i <= n; i++)
        {
            curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};