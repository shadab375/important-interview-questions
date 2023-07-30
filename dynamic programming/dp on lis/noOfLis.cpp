#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;

        for (int i=0; i<n; i++) {
            for (int prev=0; prev<i; prev++) {
                if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && dp[prev] + 1 == dp[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int nos = 0;
        for (int i=0; i<n; i++) {
            if (dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};