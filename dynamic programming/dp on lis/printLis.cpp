#include <bits/stdc++.h>
using namespace std;

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n, 1), hash(n);
  int lastIndex = 0;
  int maxi = 1;
  
  for (int i=0; i<n; i++) {
      hash[i] = i;
      for(int prev=0; prev<i; prev++) {
          if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
              dp[i] = dp[prev] + 1;
              hash[i] = prev;
          }
      }
      if (dp[i] > maxi) {
          maxi = dp[i];
          lastIndex = i;
      }
  }
  
  vector<int> temp;
  temp.push_back(arr[lastIndex]);
  while (hash[lastIndex] != lastIndex) {
      lastIndex = hash[lastIndex];
      temp.push_back(arr[lastIndex]);
  }
  reverse(temp.begin(), temp.end());
  return temp;
}