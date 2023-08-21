#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i==0 || j==0 || i==n-1 || j==m-1) {
                    if (grid[i][j] == 'O') {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

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

                if (isSafe(new_x, new_y) && grid[new_x][new_y] == 'O' && !vis[new_x][new_y]) {
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j]) grid[i][j] = 'X';
            }
        }
    }
};