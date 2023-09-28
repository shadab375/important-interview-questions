#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<int>> adj[n];
        vector<int> dist(n, 1e9);

        for (auto &it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, int>> q;
        dist[src] = 0;
        q.push({0, src});

        int stops = 0;

        while (!q.empty() && stops<=k) {
            int size = q.size();
            
            for (int i=0; i<size; i++) {
                int nodeDist = q.front().first;
                int node = q.front().second;
                q.pop();

                for (auto &it: adj[node]) {
                    int adjNode = it[0];
                    int edgeWeight = it[1];

                    if (nodeDist + edgeWeight < dist[adjNode]) {
                        dist[adjNode] = nodeDist + edgeWeight;
                        q.push({dist[adjNode], adjNode});
                    }
                }
            }
            stops++;
        }

        if (dist[dest] == 1e9) return -1;
        return dist[dest];
    }
};
