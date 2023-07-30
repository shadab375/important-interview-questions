lass Solution {
public:
    bool isPossible(vector<int>& wt, int mid, int days){
        int d = 1;
        int sum = 0;
        
        for (int i=0; i<wt.size(); i++){
            sum += wt[i];
            if (sum > mid){
                d++;
                sum = wt[i];
            }
        }
        return d <= days;
    }

    int shipWithinDays(vector<int>& wt, int days) {
        int maxi = 0, sum = 0;
        for (int i=0; i<wt.size(); i++){
            sum += wt[i];
            maxi = max(maxi, wt[i]);
        }

        if (wt.size() == days) return maxi;
        
        int lo = maxi, hi = sum;
        int ans = 0;

        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if (isPossible(wt, mid, days) == true){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};