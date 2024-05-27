// Method 1 - Brute Force
class Solution {
public:
    int findGreaterEqual(vector<int>& nums, int x) {
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] >= x) cnt++;
        }
        return cnt;
    }

    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            int count = findGreaterEqual(nums, x);
            if (count == x) return x;
        }
        return -1;
    }
};

// Method 2 - Binary Search + Linear Search on x
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int x=0; x<=n; x++) {
            int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            count = n - idx;
            if (count == x) return x;
        }
        return -1;
    }
};

// Method 3 - Binary Search twice
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // Double binary-search approach

        int l = 0, r = n;
        while (l <= r) {
            int mid_x = l + (r-l)/2;
            int idx = lower_bound(nums.begin(), nums.end(), mid_x) - nums.begin();
            int count = n - idx;
            if (count == mid_x) {
                return mid_x;
            } else if (count > mid_x) {
                l = mid_x + 1;
            } else {
                r = mid_x - 1;
            }
        }

        return -1;
    }
};

// Method 4 - cumulative sum method (important)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);

        for (int i=0; i<n; i++) {
            int num = nums[i];
            freq[min(n, num)]++;
        }

        int cum_sum = 0;
        for (int x=n; x>=0; x--) {
            cum_sum += freq[x];
            if (x == cum_sum) return x;
        }

        return -1;
    }
};