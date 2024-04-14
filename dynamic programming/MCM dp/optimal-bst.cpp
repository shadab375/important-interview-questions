//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int g=0; g<n; g++) {
            for (int i=0, j=g; j<n; i++, j++) {
                if (g == 0) {
                    dp[i][j] = freq[i];
                } else if (g == 1) {
                    int f1 = freq[i];
                    int f2 = freq[j];
                    dp[i][j] = min(f1 + 2*f2, f2 + 2*f1);
                } else {
                    int mini = INT_MAX;
                    int fs = 0;
                    for (int x=i; x<=j; x++) {
                        fs += freq[x];
                    }
                    
                    for (int k=i; k<=j; k++) {
                        int left = k == i ? 0 : dp[i][k-1];
                        int right = k == j ? 0 : dp[k+1][j];
                        
                        if (left + right + fs < mini) {
                            mini = left + right + fs;
                        }
                    }
                    
                    dp[i][j] = mini;
                }
            }
        }
        
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends