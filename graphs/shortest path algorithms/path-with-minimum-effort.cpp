#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> result(n, vector<int>(m, 1e9));

        priority_queue<P, vector<P>, greater<P>> pq;
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (auto &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                auto isSafe = [&](int x, int y) {
                    return x>=0 && x<n && y>=0 && y<m;
                };

                if (isSafe(new_x, new_y)) {
                    int newEffort = max(abs(heights[x][y] - heights[new_x][new_y]), diff);
                    if (newEffort < result[new_x][new_y]) {
                        result[new_x][new_y] = newEffort;
                        pq.push({newEffort, {new_x, new_y}});
                    }
                }
            }
        }

        return result[n-1][m-1];
    }
};