#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        map<int, int> mp;   

        for (int i=0; i<n; i++) {
            int more = target - arr[i];
            if (mp.find(more) != mp.end()) return {mp[more], i};
            mp[arr[i]] = i;
        }
        
        return {-1, -1};
    }
};