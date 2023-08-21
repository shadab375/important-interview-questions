#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {
        vector<vector<int>> adj[n+1];

        for (auto &it: times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n+1, 1e9);
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (nodeDist + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = nodeDist + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;

        for (int i=1; i<=n; i++) {
            ans = max(ans, dist[i]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};