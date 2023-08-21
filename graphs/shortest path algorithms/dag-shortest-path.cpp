//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++
class Solution {
  public:
  
    void dfs(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = true;
        
        for (auto &it: adj[node]) {
            int adjNode = it.first;
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis, st);
            }
        }
        
        st.push(node);
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        vector<int> vis(N, 0);
        
        for (auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        
        stack<int> st;
        for (int i=0; i<N; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            for (auto &it: adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if (dist[node] + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeWeight;
                }
            }
        }
        
        for (int i=0; i<N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends