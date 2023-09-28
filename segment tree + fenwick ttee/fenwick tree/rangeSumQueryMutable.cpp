class NumArray {
public:

    static const int n = 3*1e4+5;
    int bit[n] = {0};
    int arr[n] = {0};

    NumArray(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        for (int j=i+1; j<n; j+=(j&-j)) {
            bit[j] += val - arr[i+1];
        }
        arr[i+1] = val;
    }
    
    int sum(int i) {
        int ans = 0;
        for (; i>0; i-=(i&-i)) {
            ans += bit[i];
        }
        return ans;
    }

    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */