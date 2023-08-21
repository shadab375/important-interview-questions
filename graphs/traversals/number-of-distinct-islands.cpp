//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    vector<vector<int>> directions{{-1,0}, {1, 0}, {0, 1}, {0, -1}};
    int n, m;
    
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& vec, int x0, int y0) {
        vis[x][y] = 1;
        vec.push_back({x-x0, y-y0});
        
        for (auto &dir: directions) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];
            
            auto isSafe = [&](int x, int y) {
                return x>=0 && x<n && y>=0 && y<m;
            };
            
            if (isSafe(new_x, new_y) && !vis[new_x][new_y] && grid[new_x][new_y] == 1) {
                dfs(new_x, new_y, grid, vis, vec, x0, y0);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends