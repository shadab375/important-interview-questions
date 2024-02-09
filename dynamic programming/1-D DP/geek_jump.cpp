// Memoization
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& heights, int n) {
        vector<int> dp(n, 0);
        dp[0] = 0;
        
        for (int i=1; i<n; i++) {
            int one_step = dp[i-1] + abs(heights[i] - heights[i-1]);
            int two_step = INT_MAX;
            if (i - 2 >= 0) two_step = dp[i-2] + abs(heights[i] - heights[i-2]);
            dp[i] = min(one_step, two_step);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends


// Tabulation
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& heights, int n) {
        vector<int> dp(n, 0);
        dp[0] = 0;
        
        for (int i=1; i<n; i++) {
            int one_step = dp[i-1] + abs(heights[i] - heights[i-1]);
            int two_step = INT_MAX;
            if (i - 2 >= 0) two_step = dp[i-2] + abs(heights[i] - heights[i-2]);
            dp[i] = min(one_step, two_step);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Space Optimized
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& heights, int n) {
        int curr, prev = 0, prev2 = 0;
        
        for (int i=1; i<n; i++) {
            int one_step = prev + abs(heights[i] - heights[i-1]);
            int two_step = INT_MAX;
            if (i - 2 >= 0) two_step = prev2 + abs(heights[i] - heights[i-2]);
            curr = min(one_step, two_step);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends

