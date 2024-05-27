class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(int idx, vector<int>& temp, vector<int>& nums) {
        if (temp.size() >= 2) {
            result.push_back(temp);
        }

        unordered_set<int> st;
        for (int i=idx; i<n; i++) {
            if (temp.empty() || nums[i] >= temp.back()) {
                if (st.count(nums[i])) continue;
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(i+1, temp, nums);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(0, temp, nums);
        return result;
    }
};