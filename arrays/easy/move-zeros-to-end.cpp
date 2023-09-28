//method-1
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> temp;
        for (int i=0; i<n; i++) {
            if (arr[i] != 0) temp.push_back(arr[i]);
        }
        for (int i=0; i<temp.size(); i++) arr[i] = temp[i];
        for (int i=temp.size(); i<n; i++) arr[i] = 0;
    }
};

//method-2
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();

        int j = -1;
        for (int i=0; i<n; i++) {
            if (a[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) return;

        for (int i=j+1; i<n; i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};