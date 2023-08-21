#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  typedef long long ll;
    typedef pair<long long, long long> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (1e9+7);
        vector<ll> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[0] = 0; ways[0]=1; pq.push({0,0});
        
        vector<P> adj[n];
        
        //making adjacency list
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        while(!pq.empty()){
            ll nodeDist = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                ll adjNode = it.first;
                ll edgeWeight = it.second;
                
                if(nodeDist+edgeWeight < dist[adjNode]){
                    dist[adjNode] = nodeDist+edgeWeight;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode],adjNode});
                } else if(nodeDist+edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};