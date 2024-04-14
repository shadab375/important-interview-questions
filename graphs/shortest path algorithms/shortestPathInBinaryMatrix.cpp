//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> directions {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        int sr = source.first, sc = source.second;
        int dr = destination.first, dc = destination.second;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        grid[sr][sc] = 0;
        int level = 0;
        
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == dr && y == dc) return level;
                
                for (auto &dir: directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    
                    auto isSafe = [&](int x, int y) {
                        return x >= 0 && x < n && y >= 0 && y < m;
                    };
                    
                    if (isSafe(nx, ny) && grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        grid[nx][ny] = 0;
                    }
                }
            }
            level++;
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends