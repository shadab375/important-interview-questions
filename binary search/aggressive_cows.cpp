// User function Template for C++

class Solution {
public:
    
    bool canPlaceCows(vector<int> &stalls, int n, int k, int minDistance){
        int cowCount  = 1;
        int lastPos = stalls[0];
        for (int i=0; i<stalls.size(); i++){
            if (stalls[i] - lastPos >= minDistance){
                cowCount++;
                lastPos = stalls[i];
            }
            if (cowCount == k) return true;
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int lo = 1;
        int hi = stalls[n-1] - stalls[0];
        int ans = 0;
        
        while (lo<=hi){
            int mid = lo + (hi-lo)/2;
            if (canPlaceCows(stalls, n, k, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};