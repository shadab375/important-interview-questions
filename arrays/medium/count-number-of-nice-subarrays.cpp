class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        for (int i=0; i<v.size(); i++) {
            if (v[i] & 1) v[i] = 1;
            else v[i] = 0;
        }

        int preSum = 0, count = 0;
        mp[0] = 1;
        for (int i=0; i<v.size(); i++) {
            preSum += v[i];
            count += mp[preSum - k];
            mp[preSum]++;
        }

        return count;
    }
};