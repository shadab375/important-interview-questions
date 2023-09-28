#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int N;
    class DisjointSet {
    public:
        vector<int> rank, parent;

        DisjointSet (int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i=0; i<n; i++) parent[i] = i;
        }

        int find_ulp(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find_ulp(parent[x]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = find_ulp(u);
            int ulp_v = find_ulp(v);

            if (ulp_u == ulp_v) return;

            if (rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }
            else if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };

    int Kruskal(vector<vector<int>>& vec, int skip_edge, int add_edge) {
        int sum = 0;
        DisjointSet ds(N);

        if (add_edge != -1) {
            ds.unionByRank(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
        }

        for (int i=0; i<vec.size(); i++) {
            if (i == skip_edge) continue;
            int u = vec[i][0];
            int v = vec[i][1];
            int wt = vec[i][2];

            int ulp_u = ds.find_ulp(u);
            int ulp_v = ds.find_ulp(v);

            if (ulp_u != ulp_v) {
                ds.unionByRank(u, v);
                sum += wt;
            }
        }

        for (int i=0; i<N; i++) {
            if (ds.find_ulp(i) != ds.find_ulp(0)) return INT_MAX;
        }

        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        
        for (int i=0; i<edges.size(); i++) {
            edges[i].push_back(i);
        } 

        auto lambda = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };
        sort (begin(edges), end(edges), lambda);

        int MST_WEIGHT = Kruskal(edges, -1, -1);
        
        vector<int> critical, pseudo_critical;

        for (int i=0; i<edges.size(); i++) {
            if (Kruskal(edges, i, -1) > MST_WEIGHT) critical.push_back(edges[i][3]);
            else if (Kruskal(edges, -1, i) == MST_WEIGHT) pseudo_critical.push_back(edges[i][3]);
        }

        return {critical, pseudo_critical};
    }
};