//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(N, 0);
	    queue<int> q;
	    
	    //step-1: set indegree for every node
	    for (int u=0; u<N; u++) {
	        for (auto &v: adj[u]) {
	            indegree[v]++;
	        }
	    }
	    
	    //step-2: push into queue those nodes whose indegree is 0
	    for (int i=0; i<N; i++) {
	        if (indegree[i] == 0) q.push(i);
	    }
	    
	    //step-3: do bfs, and push into q as soon as indegree == 0
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	        
	        for (auto &v: adj[u]) {
	            indegree[v]--;
	            if (indegree[v] == 0) q.push(v);
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends