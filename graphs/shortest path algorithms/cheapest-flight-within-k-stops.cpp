class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int destination, int k) {
        vector<int> distance(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(vector<int> &vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            
            adj[u].push_back({v, wt});
        }
        
        queue<pair<int, int>> q;
        q.push({0, src});
        distance[src] = 0;
        
        int level = 0;
        
        while(!q.empty() && level <= k) {
            int N = q.size();
            
            while(N--) {
                int nodeDist = q.front().first;
                int node = q.front().second;
                q.pop();
                
                for(auto &it : adj[node]) {
                    int adjNode = it.first;
                    int edgeWeight = it.second;
                    
                    if(distance[adjNode] > nodeDist + edgeWeight) {
                        distance[adjNode] = nodeDist + edgeWeight;
                        q.push({distance[adjNode], adjNode});
                    }
                }
            }
            level++;
        }
        
        return distance[destination] == INT_MAX ? -1 : distance[destination];
    }
};
