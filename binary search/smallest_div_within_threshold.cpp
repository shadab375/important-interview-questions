class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            hi = max(hi, nums[i]);
        }
        if (threshold == nums.size()){
            return hi;
        }
        int minDiv = INT_MAX;

        while (lo <= hi){
            int div = lo + (hi - lo)/2;
            if (isPossible(nums, div, threshold)){
                minDiv = div;
                hi = div-1;
            }
            else{
                lo = div+1;
            }
        }
        return minDiv;
    }

    bool isPossible(vector<int> nums, int div, int threshold){
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += ceil(nums[i] * 1.0/div);
        }
        return sum <= threshold;
    }
};