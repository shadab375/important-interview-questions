#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        int cntFresh = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) cntFresh++;
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int time = 0;
        int cnt = 0;
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int curTime = q.front().second;
            q.pop();
            time = max(time, curTime);

            for (auto &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                auto isSafe = [&](int x, int y) {
                    return x>=0 && x<n && y>=0 && y<m;
                };

                if (isSafe(new_x, new_y) && grid[new_x][new_y] == 1 && !vis[new_x][new_y]){
                    vis[new_x][new_y] = 1;
                    q.push({{new_x, new_y}, curTime+1});
                    cnt++;
                }
            }
        }

        if (cnt != cntFresh) return -1;
        return time;
    }
};