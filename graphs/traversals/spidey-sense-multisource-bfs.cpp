//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};    
public:
    vector<vector<int> > findDistance(vector<vector<char> >& grid, int n, int m) 
    { 
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'B') {
                    ans[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = 1;
                } else if (grid[i][j] == 'W') {
                    ans[i][j] = -1;
                }
            }
        }
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (auto &dir: directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                auto isSafe = [&](int x, int y) {
                    return x >= 0 && x < n && y >= 0 && y < m;
                };
                
                if (isSafe(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'O') {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (ans[i][j] == INT_MAX) ans[i][j] = -1;
            }
        }
        
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
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends