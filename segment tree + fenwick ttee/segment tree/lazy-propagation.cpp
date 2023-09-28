#include <bits/stdc++.h>
using namespace std;

class ST {
private:
    vector<int> seg, lazy;
public:
    ST(int n) {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }

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

    void update(int ind, int low, int high, int l, int r, int val) {
        if (lazy[ind] != 0) {
            seg[ind] += (r - l + 1) * val;
            if (low != high) {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            lazy[ind] = 0;
        }

        if (l > high || r < low) return;
        if (low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            if (low != high) {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }

        int mid = (low + high) / 2;
        update(2*ind+1, low, high, l, r, val);
        update(2*ind+2, mid+1, high, l, r, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r) {
        if (lazy[ind] != 0) {
            seg[ind] += (high-low+1) * lazy[ind];
            if (low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (l > high || r < low) return 0;
        if (low >= l && high <= r) return seg[ind];

        int mid = (low + high) / 2;
        int left = query(2*ind+1, low, mid, l , r);
        int right = query(2*ind+2, mid+1, high, l, r);

        return left + right;
    }

};