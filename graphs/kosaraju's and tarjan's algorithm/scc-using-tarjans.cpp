//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
	
	int timer = 0;
	void dfs(int u, vector<int> adj[], vector<int>& disc, vector<int>& low,
	stack<int>& st, vector<bool>& inStack, vector<vector<int>>& ans) {
	    low[u] = disc[u] = timer;
	    timer++;
	    st.push(u);
	    inStack[u] = true;
	    
	    vector<int> temp;
	    
	    for (auto &v: adj[u]) {
	        if (disc[v] == -1) {
	            dfs(v, adj, disc, low, st, inStack, ans);
	            low[u] = min(low[u], low[v]);
	        }
	        else if (inStack[v]) {
	            low[u] = min(low[u], disc[v]);
	        }
	    }
	    
	    
	    if (low[u] == disc[u]) {
	        while (st.top() != u) {
    	        temp.push_back(st.top());
    	        inStack[st.top()] = false;
    	        st.pop();  
	        }
	        
    	    temp.push_back(st.top());
    	    inStack[st.top()] = false;
    	    st.pop();
            
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
	    } 
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> disc(V, -1), low(V, -1);
        stack<int> st;
        vector<bool> inStack(V, false);
        
        for (int i=0; i<V; i++) {
            if (disc[i] == -1) {
                dfs(i, adj, disc, low, st, inStack, ans);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends