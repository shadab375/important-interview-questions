#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (b.size() < a.size()) return findMedianSortedArrays(b, a);
        int n = a.size();
        int m = b.size();
        int lo = 0, hi = n;
        int te = n + m;

        while (lo <= hi){
            int aleft = (lo + hi)/2;
            int bleft = (te + 1)/2 - aleft;

            int alm1 = (aleft == 0) ? INT_MIN : a[aleft - 1];
            int al = (aleft == n) ? INT_MAX : a[aleft];
            int blm1 = (bleft == 0) ? INT_MIN : b[bleft - 1];
            int bl = (bleft == m) ? INT_MAX : b[bleft];

            //valid segregation
            if (alm1 <= bl && blm1 <= al){
                double median = 0.0;
                if (te % 2 == 0){
                    int lMax = max(alm1, blm1);
                    int rMin = min(al, bl);
                    median = (lMax + rMin)/2.0;
                }
                else{
                    int lMax = max(alm1, blm1);
                    median = lMax;
                }
                return median;
            }
            else if (alm1 > bl){
                //there are more elements to be picked in left part of 'b' array
                hi = aleft - 1;
            }
            else if (blm1 > al){
                //there are more elements to be picked in left part of 'a' array
                lo = aleft + 1;
            }
        }
        return 0.0;
        
    }
};