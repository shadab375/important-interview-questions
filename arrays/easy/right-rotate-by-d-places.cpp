#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void rotate(vector<int>& a, int d) {
        int n = a.size();
        d = d%n;
        
        reverse(a.begin(), a.begin() + n-d);
        reverse(a.begin() + n-d, a.end());
        reverse(a.begin(), a.end());
    }
};