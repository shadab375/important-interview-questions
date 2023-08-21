#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> directions{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {1, 0}, 
    {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> P;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 0 || m == 0 || grid[0][0] != 0) return -1;

        auto isSafe = [&](int x, int y) {
            return x>=0 && x<n && y>=0 && y<m;
        };

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0][0] = 0; 
        pq.push({0, {0, 0}});
        

        while (!pq.empty()) {
            int nodeDist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (auto &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                int edgeWeight = 1;

                if (isSafe(new_x, new_y) && grid[new_x][new_y] == 0) {
                    if (nodeDist + edgeWeight < dist[new_x][new_y]) {
                        dist[new_x][new_y] = nodeDist + edgeWeight;
                        pq.push({nodeDist+edgeWeight, {new_x, new_y}});
                    }
                }
            }
        }

        if (dist[n-1][m-1] == 1e9) return -1;
        return dist[n-1][m-1] + 1;
    }
};