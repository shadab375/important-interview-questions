//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    int n, m;
    
    void dfs(vector<vector<int>>& grid, int x, int y, int &area) {
        area++;
        grid[x][y] = 0;

        for (auto &dir: directions) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];

            auto isSafe = [&](int x, int y) {
                return x >= 0 && x < n && y >=0 && y < m;
            };

            if (isSafe(new_x, new_y) && grid[new_x][new_y] == 1) {
                dfs(grid, new_x, new_y, area);
            }
        }
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    ans = max(ans, area);
                }
            }
        }   

        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    int n, m;

    void bfs(vector<vector<int>>& grid, int x, int y, int &area) {
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second; 
            q.pop();
            area++;

            for (auto &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                auto isSafe = [&](int x, int y) {
                    return x >= 0 && x < n && y >=0 && y < m;
                };

                if (isSafe(new_x, new_y) && grid[new_x][new_y] == 1) {
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = 0;
                }
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    bfs(grid, i, j, area);
                    ans = max(ans, area);
                }
            }
        }   

        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends