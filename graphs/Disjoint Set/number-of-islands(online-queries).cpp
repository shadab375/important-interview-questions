//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
public:
    vector<int> rank, parent, size;
    
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        parent.resize(n+1, 0);
        
        for (int i=0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_ulp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find_ulp(parent[x]);
    }
    
    void unionBySize(int x, int y) {
        int ulp_x = find_ulp(x);
        int ulp_y = find_ulp(y);
        if (ulp_x == ulp_y) return;
        
        if (size[ulp_x] < size[ulp_y]) {
            parent[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        }
        
        else {
            parent[ulp_y] = ulp_x;
            size[ulp_x] += size[ulp_y];
        }
    }
};

class Solution {
  public:
  
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        vector<int> ans;
        
        for (auto it: operators) {
            int row = it[0];
            int col = it[1];
            
            if (vis[row][col]) {
                ans.push_back(count);
                continue;
            }
            
            vis[row][col] = 1;
            count++;
            
            for (auto dir: directions) {
                int adjr = row + dir[0];
                int adjc = col + dir[1];
                
                auto isSafe = [&](int x, int y) {
                    return x>=0 && x<n && y>=0 && y<m; 
                };
                
                if (isSafe(adjr, adjc) && vis[adjr][adjc]) {
                    int node = row*m + col;
                    int adjNode = adjr*m + adjc;
                    
                    if (ds.find_ulp(node) != ds.find_ulp(adjNode)) {
                        ds.unionBySize(node, adjNode);
                        count--;
                    }
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends