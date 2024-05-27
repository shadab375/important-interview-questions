class Solution {
public:
    int result;
    int k;

    void solve(int idx, vector<int>& nums, unordered_map<int ,int>& mp) {
        if (idx >= nums.size()) {
            result++;
            return;
        }

        solve(idx+1, nums, mp);

        if (!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
            mp[nums[idx]]++;
            solve(idx+1, nums, mp);
            mp[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int K) {
        result = 0;
        k = K;
        unordered_map<int, int> mp;
        solve(0, nums, mp);
        return result - 1;
    }
};