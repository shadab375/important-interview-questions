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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (isConnected[i][j]) ds.unionBySize(i, j);
            }
        }

        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (ds.find_ulp(i) == i) cnt++;
        }

        return cnt;
    }
};