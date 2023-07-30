class Solution {
public:
    int solve(int e,int f,vector<vector<int>> &dp){
        if(e==1){
            return f;
        }

        if(f==0 || f==1) return f;

        if(dp[e][f]!=-1) return dp[e][f];

        int mini=INT_MAX;
        for(int i=1;i<f;++i){
            int Break=solve(e-1,i-1,dp);
            int notBreak=solve(e,f-i,dp);
            int temp=1+max(Break,notBreak);
            mini=min(mini,temp);
        }

        return dp[e][f]=mini;
    }

    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return solve(2,n,dp);
    }
};