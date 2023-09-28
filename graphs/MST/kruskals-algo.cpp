//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> rank;
	vector<int> parent;
	
	int find_ulp(int x) {
	    if (parent[x] == x) return x;
	    return parent[x] = find_ulp(parent[x]);
	}
	
	void Union(int x, int y) {
	    int ulp_x = find_ulp(x);
	    int ulp_y = find_ulp(y);
	    
	    if (rank[ulp_x] > rank[ulp_y]) {
	        parent[ulp_y] = ulp_x;
	    }
	    else if (rank[ulp_x] < rank[ulp_y]) {
	        parent[ulp_x] = ulp_y;
	    }
	    else {
	        parent[ulp_x] = ulp_y;
	        rank[ulp_y]++;
	    }
	}
	
	int kruskal(vector<vector<int>>& vec) {
	    int sum = 0;
	    
	    for (auto &it: vec) {
	        int u = it[0];
	        int v = it[1];
	        int wt = it[2];
	        
	        int ulp_u = find_ulp(u);
	        int ulp_v = find_ulp(v);
	        
	        if (ulp_u != ulp_v) {
	            Union(u, v);
	            sum += wt;
	        }
	    }
	    
	    return sum;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        rank.resize(V, 0);
        parent.resize(V);
        for (int i=0; i<V; i++) parent[i] = i;
        
        vector<vector<int>> vec;
        
        for (int u=0; u<V; u++) {
            for (auto &it: adj[u]) {
                int v = it[0];
                int wt = it[1];
                vec.push_back({u, v, wt});
            }
        }
        
        auto comparator = [&](auto& vec1, auto& vec2) {
            return vec1[2] < vec2[2];
        };


        
        sort(vec.begin(), vec.end(), comparator);
        
        return kruskal(vec);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends