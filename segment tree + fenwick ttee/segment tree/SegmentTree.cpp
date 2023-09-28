#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:

    int n;
    vector<int> seg;

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void upd(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid) upd(2*ind+1, low, mid, i, val);
        else upd(2*ind+2, mid+1, high, i, val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r) {
        if (low > r || high < l) return 0;
        if (low >= l && high <= r) return seg[ind];

        int mid = (low + high) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);

        return left + right;
    }

    NumArray(vector<int>& arr) {
        n = arr.size();
        seg.resize(4*n+1);
        build(0, 0, n-1, arr);
    }
    
    void update(int i, int val) {
        upd(0, 0, n-1, i, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */