//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> directions {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
        int sx = KnightPos[0] - 1, sy = KnightPos[1] - 1;
        int tx = TargetPos[0] - 1, ty = TargetPos[1] - 1;
        vector<vector<int>> visited(N, vector<int>(N, 0));
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{sx, sy}, 0});
        
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if (x == tx && y == ty) return steps;
            
            for (auto &dir: directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                auto isSafe = [&](int x, int y) {
                    return x >= 0 && x < N && y >=0 && y < N;
                };
                
                if (isSafe(nx, ny) && !visited[nx][ny]) {
                    q.push({{nx, ny}, steps+1});
                    visited[nx][ny] = 1;
                }
            }
        }
        
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends