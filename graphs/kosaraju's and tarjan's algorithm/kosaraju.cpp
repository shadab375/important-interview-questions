//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfsFill(int u, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
	    vis[u] = 1;
	    for (auto &v: adj[u]) {
	        if (!vis[v]) {
	            dfsFill(v, adj, vis, st);
	        }
	    }
	    st.push(u);
	}
	
	void dfsTraversal(int u, vector<vector<int>>& adjReversed, vector<int>& vis) {
	    vis[u] = 1;
	    for (auto &v: adjReversed[u]) {
	        if (!vis[v]) {
	            dfsTraversal(v, adjReversed, vis);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        
        //step-1: arrange the given graph in topo sort order
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                dfsFill(i, adj, vis, st);
            }
        }
        
        //step-2: reverse the given graph
        vector<vector<int>> adjReversed(V); 
        for (int u=0; u<V; u++) {
            for (auto &v: adj[u]) {
                adjReversed[v].push_back(u);  
            }
        }
        
        //step-3: do a dfs traversal in stack order to count the scc
        int countScc = 0;
        vis = vector<int>(V, 0);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                dfsTraversal(node, adjReversed, vis);
                countScc++;
            }
        }
        
        return countScc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends