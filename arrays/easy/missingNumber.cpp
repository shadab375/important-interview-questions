#include <bits/stdc++.h> 
using namespace std;

//method-1
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        int sum = n * (n + 1) / 2;
        int s2 = 0;
        
        for (int i = 0; i < n; i++) {
            s2 += nums[i];
        }

        return sum - s2;
    }
};

//method-2
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor1 = xor1 ^ i;
            xor2 = xor2 ^ nums[i];
        }
        xor1 = xor1 ^ n;

        return (xor1 ^ xor2); 
    }
};

