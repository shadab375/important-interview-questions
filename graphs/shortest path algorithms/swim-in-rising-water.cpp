#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    class cell {
    public:
        int x;
        int y;
        int timeRequired;

        cell(int x, int y, int timeRequired) {
            this->x = x;
            this->y = y;
            this->timeRequired = timeRequired;
        }
    };

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        auto lambda = [&](auto& cell1, auto& cell2) {
            return cell1.timeRequired > cell2.timeRequired;
        };

        priority_queue<cell, vector<cell>, decltype(lambda)> pq(lambda);
        pq.push(cell(0, 0, grid[0][0]));
        vis[0][0] = 1;
        int leastTime = grid[0][0];

        while (!pq.empty()) {
            cell curCell = pq.top();
            pq.pop();
            leastTime = max(leastTime, curCell.timeRequired);
            if (curCell.x >= n-1 && curCell.y >= m-1) break;

            for (auto &dir: directions) {
                int new_x = curCell.x + dir[0];
                int new_y = curCell.y + dir[1];

                auto isSafe = [&](int x, int y) {
                    return x>=0 && x<n && y>=0 && y<m;
                };

                if (isSafe(new_x, new_y) && !vis[new_x][new_y]) {
                    vis[new_x][new_y] = 1;
                    pq.push(cell(new_x, new_y, grid[new_x][new_y]));
                }
            }
        }

        return leastTime;
    }
};