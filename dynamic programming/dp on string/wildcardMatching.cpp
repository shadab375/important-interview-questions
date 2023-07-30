#include <bits/stdc++.h>
using namespace std;

//RECURSION + MEMOIZATION

//METHOD - 1
class Solution {
public:

    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i<0 && j<0) return true;
        if (i<0 && j>=0) return false;
        if (j<0 && i>=0){
            for (int k=0; k<=i; k++) {
                if (s1[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j] || s1[i] == '?')
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        if (s1[i] == '*') 
            return dp[i][j] = f(i-1, j, s1, s2, dp)|f(i, j-1, s1, s2, dp);


        return dp[i][j] = false;
    }

    bool isMatch(string s2, string s1) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s1, s2, dp);
    }
};

//METHOD - 2
class Solution {
public:

    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i==0 && j==0) return true;
        if (i==0 && j>0) return false;
        if (j==0 && i>0){
            for (int k=1; k<=i; k++) {
                if (s1[k-1] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i-1] == s2[j-1] || s1[i-1] == '?') {
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        }
        if (s1[i-1] == '*') {
            return dp[i][j] = f(i-1, j, s1, s2, dp) | f(i, j-1, s1, s2, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s2, string s1) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(n, m, s1, s2, dp);



    }
};

//TABULATION

class Solution {
public:

    bool isMatch(string s2, string s1) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        //BASE CASE
        dp[0][0] = true;
        for (int j=1; j<=m; j++) {
            dp[0][j] = false;
        }
        for (int i=1; i<=n; i++) {
            bool flag = true;
            for (int k=1; k<=i; k++) {
                if (s1[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        //COPY RECURRENCE
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (s1[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};