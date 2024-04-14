//recursion + memoization
#include <bits/stdc++.h>
using namespace std;

bool f(int ind, int target, vector < int > & arr, vector < vector 
< int >> & dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = (arr[0] == target);

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTake = f(ind - 1, target, arr, dp);

  bool take = false;
  if (arr[ind] <= target)
    take = f(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTake || take;
}

int minSubsetSumDifference(vector < int > & arr, int n) {

  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector<vector<int>> dp(n, vector<int>(totSum+1, -1));

  for (int i = 0; i <= totSum; i++) {
    bool dummy = f(n - 1, i, arr, dp);
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum/2; i++) {
    if (dp[n - 1][i] == true) {
      int s1 = i;
			int s2 = totSum - i;
			mini = min(mini, abs(s1 - s2));
    }
  }
  return mini;

}

//tabulation
#include <bits/stdc++.h> 
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;
	for (int i=0; i<n; i++) totSum += arr[i];
	int k = totSum;

	vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
	for (int i=0; i<n; i++) dp[i][0] = true;
	if (arr[0] <= k) dp[0][arr[0]] = true;

	for (int ind=1; ind<n; ind++){
		for (int target=1; target<=k; target++){
			bool notTake = dp[ind-1][target];
			bool take = false;
			if (arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
			dp[ind][target] = take|notTake;
		}
	}

	int mini = 1e9;
	for (int i=0; i<=totSum/2; i++){
		if (dp[n-1][i] == true){
			int s1 = i;
			int s2 = totSum - s1;
			mini = min(mini, abs(s1 - s2));
		}
	}
	return mini;
}

//space optimization
#include <bits/stdc++.h> 
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;
	for (int i=0; i<n; i++) totSum += arr[i];
	int k = totSum;

	vector<bool> prev(k+1, 0), cur(k+1, 0);
  prev[0] = cur[0] = 1;
	if (arr[0] <= k) prev[arr[0]] = true;

	for (int ind=1; ind<n; ind++){
		for (int target=1; target<=k; target++){
			bool notTake = prev[target];
			bool take = false;
			if (arr[ind]<=target) take = prev[target-arr[ind]];
			cur[target] = take|notTake;
		}
    prev = cur;
	}

	int mini = 1e9;
	for (int s1=0; s1<=totSum/2; s1++){
		if (prev[s1] == true){
			int s2 = totSum - s1;
			mini = min(mini, abs(s2 - s1));
		}
	}
	return mini;
}

