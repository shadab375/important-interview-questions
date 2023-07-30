//RECURSION + MEMOIZATION

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
	
	if (ind == 0) {
		if (target == 0 && arr[0] == 0) return 2;
		if (target == 0 || target == arr[0]) return 1;
		return 0;
	}
	if (dp[ind][target] != -1) return dp[ind][target];

	int notTake = f(ind-1, target, arr, dp);
	int take = 0;
	if (arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);

	return dp[ind][target] = (take + notTake)%MOD;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    /*
    s1 - s2 = d
    s1 = totSum - s2
    totSum - s2 - s2 = d
    s2 = (totSum - d) / 2
    totSum - d needs to be > 0 and even for the question to be valid, then the question boils down to count subsets wtih sum k
    */
    int totSum = 0;
    for (auto &it: arr) totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2 == 1) return 0;
    return findWays(arr, (totSum - d) / 2);
}

//TABULATION

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int findWays(vector<int>& arr, int k){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for (int ind=1; ind<n; ind++){
        for (int target=0; target<=k; target++){
            int notTake = dp[ind-1][target];
            int take = 0;
            if (arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = (notTake + take)%MOD;
        }
    }
    return dp[n-1][k];
}


int countPartitions(int n, int d, vector<int> &arr) {
    /*
    s1 - s2 = d
    s1 = totSum - s2
    totSum - s2 - s2 = d
    s2 = (totSum - d) / 2
    totSum - d needs to be > 0 and even for the question to be valid, then the question boils down to count subsets wtih target k
    */
    int totSum = 0;
    for (auto &it: arr) totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2 == 1) return 0;
    return findWays(arr, (totSum - d) / 2);

}

//SPACE OPTIMIZATION

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int findWays(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> prev(k+1, 0);
    vector<int> cur(k+1, 0);
    if (arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

    for (int ind=1; ind<n; ind++){
        for (int target=0; target<=k; target++){
            int notTake = prev[target];
            int take = 0;
            if (arr[ind] <= target) take = prev[target-arr[ind]];
            cur[target] = (notTake + take)%MOD;
        }
        prev = cur;
    }
    return prev[k];
}


int countPartitions(int n, int d, vector<int> &arr) {
    /*
    s1 - s2 = d
    s1 = totSum - s2
    totSum - s2 - s2 = d
    s2 = (totSum - d) / 2
    totSum - d needs to be > 0 and even for the question to be valid, then the question boils down to count subsets wtih target k
    */
    int totSum = 0;
    for (auto &it: arr) totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2 == 1) return 0;
    return findWays(arr, (totSum - d) / 2);

}








