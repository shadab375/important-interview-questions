//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    int n, m;
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = 'O';
        
        for (auto &dir: directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            
            auto isSafe = [&](int x, int y) {
                return x >= 0 && x < n && y >=0 && y < m;
            };
            
            if (isSafe(nx, ny) && grid[nx][ny] == 'X') {
                dfs(nx, ny, grid);
            }
        }
    }

    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {   
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'X') {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
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
    int n, m;
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void bfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = 'O';
        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (auto &dir: directions) {
                int nx = cx + dir[0];
                int ny = cy + dir[1];

                auto isSafe = [&](int x, int y) {
                    return x >= 0 && x < n && y >=0 && y < m;
                };

                if (isSafe(nx, ny) && grid[nx][ny] == 'X') {
                    grid[nx][ny] = 'O'; // Mark as visited
                    q.push({nx, ny});
                }
            }
        }
    }

    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {   
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'X') {
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends