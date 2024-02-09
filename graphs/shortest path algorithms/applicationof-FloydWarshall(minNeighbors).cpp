#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresholdDistance) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (auto &it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2]; 
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

       int ansCity = -1;
       int minNeighbors = n;

       for (int city=0; city<n; city++) {
           int neighbors = 0;
           for (int adjCity = 0; adjCity < n; adjCity++) {
               if (dist[city][adjCity] <= thresholdDistance) neighbors++;
           }

           if (neighbors <= minNeighbors) {
               minNeighbors = neighbors;
               ansCity = city;
           }
        }

        return ansCity;
    }
};