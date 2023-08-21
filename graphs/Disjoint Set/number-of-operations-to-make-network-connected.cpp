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
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int cntExtras = 0;

        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            if (ds.find_ulp(u) == ds.find_ulp(v)) cntExtras++;
            else ds.unionBySize(u, v);
        }

        int cntC = 0;
        for (int i=0; i<n; i++) {
            if (ds.find_ulp(i) == i) cntC++; 
        }

        int edgesRequired = cntC - 1;
        
        if (cntExtras >= edgesRequired) return edgesRequired;
        return -1;
    }
};