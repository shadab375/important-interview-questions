class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 0, hi = INT_MIN;
        for (int i=0; i<piles.size(); i++){
            hi = max(hi, piles[i]);
        }

        if (hi == piles.size()) return hi;
        int minSpeed = INT_MAX;

        while (lo <= hi){
            int sp = lo + (hi - lo)/2;
            if (isPossible(piles, h, sp)){
                minSpeed = sp;
                hi = sp -1;
            }
            else{
                lo = sp+1;
            }
        }
        return minSpeed;

    }

    bool isPossible(vector<int> piles, int h, int sp){
        double time = 0;
        for (int i=0; i<piles.size(); i++){
            time += ceil(piles[i] * 1.0/sp);
        }
        return time <= h;
    }
};