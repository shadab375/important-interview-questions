//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int mod = 100000;
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = 100000;
        vector<int> dist(n, 1e9);
        
        queue<pair<int, int>> q;
        dist[start] = 0;
        q.push({0, start});
        if (start == end) return 0;
        
        while (!q.empty()) {
            int nodeDist = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for (auto &it: arr) {
                int adjNode = (it*node)%mod;
                int edgeWeight = 1;
                
                if (nodeDist + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = nodeDist + edgeWeight;
                    if (adjNode == end) return dist[adjNode];
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends