class Solution {
public:

    int solve(vector<int>& nums, int lo, int hi, int target){
        if (lo > hi) return -1;

        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return solve(nums, mid + 1, hi, target);
        else return solve(nums, lo, mid - 1, target);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        return solve (nums, 0, n - 1, target);
    }
};