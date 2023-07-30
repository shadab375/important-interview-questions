class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        int prev2 = 0, prev = 1;
        for (int i=2; i<=n; i++){
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};

class Solution {
public:
    int fib(int n) {
        vector<int> dp (n+2, -1);
        dp[0] = 0, dp[1] = 1;
        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        int prev = 0, prev2 = 0;
        
        for (int i = 1; i < n; i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if (i>1) ss = prev2 + abs(height[i] - height[i - 2]);
            
            int curi = min(fs, ss);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};