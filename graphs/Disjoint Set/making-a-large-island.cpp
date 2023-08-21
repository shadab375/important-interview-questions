#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 0);

        for (int i=0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_ulp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find_ulp(parent[x]);
    }

    void unionBySize(int x, int y) {
        int ulp_x = find_ulp(x);
        int ulp_y = find_ulp(y);

        if (ulp_x == ulp_y) return;

        if (size[ulp_x] < size[ulp_y]) {
            parent[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        }
        else {
            parent[ulp_y] = ulp_x;
            size[ulp_x] += size[ulp_y];
        }
    }
};

class Solution {
public:

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        auto isSafe = [&](int x, int y) {
            return x>=0 && x<n && y>=0 && y<n;
        };

        for (int row=0; row<n; row++) {
            for (int col=0; col<n; col++) {
                if (grid[row][col] == 0) continue;

                for (auto &dir: directions) {
                    int adjr = row + dir[0];
                    int adjc = col + dir[1];

                    if (isSafe(adjr, adjc) && grid[adjr][adjc] == 1) {
                        int node = row*n + col;
                        int adjNode = adjr*n + adjc;

                        if (ds.find_ulp(node) != ds.find_ulp(adjNode)) {
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        int maxi = 0;
        for (int row=0; row<n; row++) {
            for (int col=0; col<n; col++) {
                if (grid[row][col] == 1) continue;
                set<int> st;

                for (auto &dir: directions) {
                    int adjr = row + dir[0];
                    int adjc = col + dir[1];

                    if (isSafe(adjr, adjc) && grid[adjr][adjc] == 1) {
                        int adjNode = adjr*n + adjc;
                        st.insert(ds.find_ulp(adjNode));
                    }
                }

                int totalSize = 0;
                for (auto &it: st) {
                    totalSize += ds.size[it];
                }

                maxi = max(maxi, totalSize + 1);
            }
        }

        maxi = max(maxi, ds.size[ds.find_ulp(0)]);
        return maxi;
    }
};
};