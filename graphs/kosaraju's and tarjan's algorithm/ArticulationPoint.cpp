//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int timer = 0;
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc,
    vector<int>& low, vector<int>& ap) {
        disc[u] = low[u] = timer;
        timer++;
        int children = 0;
        
        for (auto &v: adj[u]) {
            if (disc[v] == -1) {
                children++;
                dfs(v, u, adj, disc, low, ap);
                low[u] = min(low[u], low[v]);
                
                if (parent == -1 && children > 1) ap[u] = 1;
                if (parent != -1 && low[v] >= disc[u]) ap[u] = 1;
            }
            else if (v != parent) low[u] = min(low[u], disc[v]);
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> ans;
        vector<int> ap(V, 0);
        vector<int> low(V, -1), disc(V, -1);
        
        for (int i=0; i<V; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, adj, disc, low, ap);
            }
        }
        
        for (int i=0; i<V; i++) {
            if (ap[i]) ans.push_back(i);
        }
        
        if (ans.empty()) {
            ans.push_back(-1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends