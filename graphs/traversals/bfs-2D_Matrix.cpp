//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    vector<vector<int>> directions{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void bfs(int source_x, int source_y, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[source_x][source_y] = 1;
        queue<pair<int, int>> q;
        q.push({source_x, source_y});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            auto isSafe = [&](int x, int y) {
                return x>=0 && x<n && y>=0 && y<m;
            };
            
            for (auto &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if (isSafe(new_x, new_y) && grid[new_x][new_y] == '1' &&!vis[new_x][new_y]) {
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends