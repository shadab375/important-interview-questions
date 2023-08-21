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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for (auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        for (auto it: stones) {
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            ds.unionBySize(rowNode, colNode);
        }

        int cntC = 0;
        for (int i = 0; i < (maxRow + maxCol + 2); i++) {
            if (ds.parent[i] == i && ds.size[i] > 1) cntC++;
        }

        return n - cntC;
    }
};