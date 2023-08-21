#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        auto isSafe = [&](int x, int y) {
                    return x>=0 && x<n && y>=0 && y<m;
        };

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[x][y] = dist;

            for (auto &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                

                if (isSafe(new_x, new_y) && !vis[new_x][new_y]) {
                    q.push({{new_x, new_y}, dist+1});
                    vis[new_x][new_y] = 1;
                }
            }
        }

        return ans;
    }
};