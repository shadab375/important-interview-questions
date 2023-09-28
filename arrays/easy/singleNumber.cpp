#include <bits/stdc++.h>
using namespace std;

//method-1 (good solution - applicable everywhere)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i=0; i<n; i++) mp[nums[i]]++;
        for (int i=0; i<n; i++) {
            if (mp[nums[i]] == 1) return nums[i];
        }

        return -1;
    }
};



//method-3 (most optimal - applicable only here)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        for (int i=0; i<n; i++) {
            xorr = xorr ^ nums[i];
        }

        return xorr;
    }
};