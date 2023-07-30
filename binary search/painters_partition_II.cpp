#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  
    bool isPossible(int arr[], int n, int mid, int m){
        int painters = 1, sum = 0;
        for (int i=0; i<n; i++){
            sum += arr[i];
            
            if (sum > mid){
                painters++;
                sum = arr[i];
            }
        }
        return painters <= m;
    }
    long long minTime(int arr[], int n, int m)
    {
          long long sum = 0;
          int maxi = 0;
          for (int i=0; i<n; i++){
              sum += arr[i];
              maxi = max(maxi, arr[i]);
          }
          
          int lo = maxi;
          long long hi = sum;
          int ans = 0;
          
          while (lo <= hi){
              int mid = lo + (hi - lo)/2;
              if (isPossible(arr, n, mid, m) == true){
                  ans = mid;
                  hi = mid - 1;
              }
              else{
                  lo = mid + 1;
              }
          }
          return ans;
    }
};