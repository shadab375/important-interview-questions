class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0, end = 0, farthest = 0;
        int destination = n - 1;

        for (int i=0; i<n; i++) {
            farthest = max(farthest, i+nums[i]);
            if (i == end) {
                end = farthest;
                jumps++;
                if (farthest >= destination) return jumps;
            }
        }

        return jumps;
    }
};